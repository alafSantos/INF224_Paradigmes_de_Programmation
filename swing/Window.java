import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.BorderLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.JScrollPane;
import javax.swing.JMenuBar;
import javax.swing.JToolBar;
import javax.swing.JMenu;
import javax.swing.JTextField;

public class Window extends JFrame implements ActionListener {
  private static final long serialVersionUID = 1L;
  private JTextArea textArea;
  private JButton button1, button2, btnExit, btnClear;
  private JMenuBar menuBar;
  private JMenu menu;
  private JToolBar toolBar;
  private JTextField textField;

  public Window() {
    setLayout(new BorderLayout());
    textArea = new JTextArea(10, 30);

    JScrollPane scrollableTextArea = new JScrollPane(this.textArea);
    scrollableTextArea.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
    scrollableTextArea.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);

    add(scrollableTextArea, BorderLayout.CENTER);

    button1 = new JButton("Play");
    button1.addActionListener(this);
    add(button1, BorderLayout.SOUTH);

    button2 = new JButton("Show");
    button2.addActionListener(this);
    add(button2, BorderLayout.SOUTH);

    btnClear = new JButton("Clear");
    btnClear.addActionListener(this);
    add(btnClear, BorderLayout.SOUTH);

    btnExit = new JButton("Exit");
    btnExit.addActionListener(this);
    add(btnExit, BorderLayout.SOUTH);

    textField = new JTextField();

    menu = new JMenu("Menu");
    menuBar = new JMenuBar();
    menuBar.add(menu);
    setJMenuBar(menuBar);

    toolBar = new JToolBar();
    toolBar.add(textField);
    toolBar.add(button1);
    toolBar.add(button2);
    toolBar.add(btnClear);
    toolBar.add(btnExit);
    add(toolBar, BorderLayout.NORTH);

    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    pack();
    setVisible(true);
  }

  public void actionPerformed(ActionEvent e) {

    if (e.getSource() == btnClear) {
      textArea.setText("");
    } else if (e.getSource() == btnExit) {
      System.exit(0);
    } else {
      String txt = textField.getText();
      if (e.getSource() == button1) {
        textArea.append(txt + " play\n");
      } else if (e.getSource() == button2) {
        textArea.append(txt + " show\n");
      }
    }

  }

  public static void main(String[] args) {
    new Window();
  }
}
