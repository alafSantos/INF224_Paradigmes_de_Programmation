import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.BorderLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.JScrollPane;
import javax.swing.JMenuBar;
import java.awt.Color;
import javax.swing.JToolBar;
import javax.swing.JMenu;

public class Window extends JFrame implements ActionListener {
  private static final long serialVersionUID = 1L;
  private JTextArea textArea;
  private JButton button1, button2, btnExit, btnClear;
  private JMenuBar menuBar;
  private JMenu menu;
  private JToolBar toolBar;

  public Window() {
    setSize(300, 400);
    setLayout(new BorderLayout());

    textArea = new JTextArea(10, 20);

    JScrollPane scrollableTextArea = new JScrollPane(this.textArea);
    scrollableTextArea.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
    scrollableTextArea.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);

    add(scrollableTextArea, BorderLayout.CENTER);

    button1 = new JButton("Ajouter ligne 1");
    button1.addActionListener(this);
    add(button1, BorderLayout.SOUTH);

    button2 = new JButton("Ajouter ligne 2");
    button2.addActionListener(this);
    add(button2, BorderLayout.SOUTH);

    btnExit = new JButton("Quitter");
    btnExit.addActionListener(this);
    add(btnExit, BorderLayout.SOUTH);

    btnClear = new JButton("Clear");
    btnClear.addActionListener(this);
    add(btnClear, BorderLayout.SOUTH);

    menuBar = new JMenuBar();
    menu = new JMenu("Menu");
    menuBar.add(menu);
    setJMenuBar(menuBar);

    toolBar = new JToolBar();
    toolBar.add(button1);
    toolBar.add(button2);
    toolBar.add(btnExit);
    add(toolBar, BorderLayout.NORTH);

    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    pack();
    setVisible(true);
  }

  public void actionPerformed(ActionEvent e) {
    if (e.getSource() == button1) {
      textArea.append("Ligne 1 ajoutée\n");
    } else if (e.getSource() == button2) {
      textArea.append("Ligne 2 ajoutée\n");
    } else if (e.getSource() == btnExit) {
      System.exit(0);
    }
    else if(e.getSource() == btnClear){
      textArea.setText("");
    }
  }

  public static void main(String[] args) {
    new Window();
  }
}
