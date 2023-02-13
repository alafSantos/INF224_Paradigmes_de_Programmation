import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.BorderLayout;
import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.JScrollPane;
import javax.swing.JMenuBar;
import javax.swing.JToolBar;
import javax.swing.JMenu;
import javax.swing.JTextField;
import javax.swing.JMenuItem;
import java.io.*;
import java.net.*;

public class Window extends JFrame implements ActionListener {
  private static final long serialVersionUID = 1L;
  private JTextArea textArea;
  private JButton button1, button2, btnExit, btnClear, btnAddVideo, btnRemove;
  private JMenuBar menuBar;
  private JMenu menu;
  private JToolBar toolBar, toolBar2, toolBar3;
  private JTextField textField, fileNameTextField, pathTextField, field3, field4;
  private JMenuItem multimedia, group;

  static final String DEFAULT_HOST = "localhost";
  static final int DEFAULT_PORT = 3331;
  static String host = DEFAULT_HOST;
  static int port = DEFAULT_PORT;
  static Client client = null;

  public Window() {
    setLayout(new BorderLayout());
    textArea = new JTextArea(10, 30);

    JScrollPane scrollableTextArea = new JScrollPane(this.textArea);
    scrollableTextArea.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
    scrollableTextArea.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);

    add(scrollableTextArea, BorderLayout.CENTER);

    button1 = new JButton("Play");
    button1.addActionListener(this);
    // add(button1, BorderLayout.SOUTH);

    button2 = new JButton("Show");
    button2.addActionListener(this);
    // add(button2, BorderLayout.SOUTH);

    btnClear = new JButton("Clear");
    btnClear.addActionListener(this);
    add(btnClear, BorderLayout.LINE_END);

    btnExit = new JButton("Exit");
    btnExit.addActionListener(this);
    // add(btnExit, BorderLayout.SOUTH);

    btnAddVideo = new JButton("Add Media");
    btnAddVideo.addActionListener(this);
    // add(btnAddVideo, BorderLayout.SOUTH);

    btnRemove = new JButton("Remove");
    btnRemove.addActionListener(this);
    // add(btnRemove, BorderLayout.SOUTH);

    textField = new JTextField();
    fileNameTextField = new JTextField();
    pathTextField = new JTextField();
    field3 = new JTextField();
    field4 = new JTextField();

    menu = new JMenu("List");
    menuBar = new JMenuBar();
    menuBar.add(menu);
    setJMenuBar(menuBar);

    multimedia = new JMenuItem("Multimedia");
    group = new JMenuItem("Groups");
    multimedia.addActionListener(this);
    group.addActionListener(this);
    menu.add(multimedia);
    menu.add(group);

    toolBar = new JToolBar();
    toolBar.add(textField);
    toolBar.add(button1);
    toolBar.add(button2);
    // toolBar.add(btnClear);
    toolBar.add(btnRemove);
    toolBar.add(btnExit);
    add(toolBar, BorderLayout.NORTH);

    toolBar2 = new JToolBar();
    toolBar2.add(fileNameTextField);
    toolBar2.add(pathTextField);
    toolBar2.add(field3);
    toolBar2.add(field4);
    toolBar2.add(btnAddVideo);
    add(toolBar2, BorderLayout.SOUTH);

    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    pack();
    setVisible(true);
  }

  public static void main(String argv[]) {
    if (argv.length >= 1)
      host = argv[0];
    if (argv.length >= 2)
      port = Integer.parseInt(argv[1]);

    try {
      client = new Client(host, port);
      System.out.println("Client connected to " + host + ":" + port);
    } catch (Exception excp) {
      System.err.println("Client: Couldn't connect to " + host + ":" + port);
      System.exit(1);
    }
    new Window();
  }

  // -------------------------CLIENT.JAVA-------------------------
  private static class Client {

    private Socket sock;
    private BufferedReader input;
    private BufferedWriter output;

    ///
    /// Initialise la connexion.
    /// Renvoie une exception en cas d'erreur.
    ///
    public Client(String host, int port) throws UnknownHostException, IOException {
      try {
        sock = new java.net.Socket(host, port);
      } catch (java.net.UnknownHostException e) {
        System.err.println("Client: Couldn't find host " + host + ":" + port);
        throw e;
      } catch (java.io.IOException e) {
        System.err.println("Client: Couldn't reach host " + host + ":" + port);
        throw e;
      }

      try {
        input = new BufferedReader(new InputStreamReader(sock.getInputStream()));
        output = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
      } catch (java.io.IOException e) {
        System.err.println("Client: Couldn't open input or output streams");
        throw e;
      }
    }

    ///
    /// Envoie une requete au server et retourne sa reponse.
    /// Noter que la methode bloque si le serveur ne repond pas.
    ///
    public String send(String request) {
      // Envoyer la requete au serveur
      try {
        request += "\n"; // ajouter le separateur de lignes
        output.write(request, 0, request.length());
        output.flush();
      } catch (java.io.IOException e) {
        System.err.println("Client: Couldn't send message: " + e);
        return null;
      }

      // Recuperer le resultat envoye par le serveur
      try {
        return input.readLine();
      } catch (java.io.IOException e) {
        System.err.println("Client: Couldn't receive message: " + e);
        return null;
      }
    }
  }
  // --------------------------------------------------------

  private String printResponse(String text) {
    String output = "";
    String[] txt = text.split("ç;1");
    for (String txt_i : txt)
      output += txt_i + "\n";
    return output;
  }

  public void actionPerformed(ActionEvent e) {
    if (e.getSource() == btnClear) {
      textArea.setText("");
      textField.setText("");
      fileNameTextField.setText("");
      pathTextField.setText("");
      field3.setText("");
      field4.setText("");
    } else if (e.getSource() == btnExit) {
      System.exit(0);
    } else {
      String txt = textField.getText();
      String command = null;

      if (e.getSource() == group) {
        command = "lGrp";
      } else if (e.getSource() == multimedia) {
        command = "lMlt";
      } else if (e.getSource() == button1) {
        command = "play " + txt;
      } else if (e.getSource() == button2) {
        command = "find " + txt;
      } else if (e.getSource() == btnRemove) {
        command = "remv " + txt;
      } else if (e.getSource() == btnAddVideo) {
        String str = field4.getText();
        if (str.length() > 0)
          command = "addP " + fileNameTextField.getText() + " " + pathTextField.getText() + " " + field3.getText() + " "
              + field4.getText();
        else
          command = "addV " + fileNameTextField.getText() + " " + pathTextField.getText() + " " + field3.getText();
      }

      System.out.print("Request: " + command + "\n");
      try {
        String response = client.send(command);
        response = printResponse(response);
        System.out.println("Response:\n" + response);
        textArea.append(response);
      } catch (Exception excp) {
        System.err.println("Client: error");
        return;
      }
    }
  }
}
