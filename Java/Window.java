import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.JScrollPane;

public class Window extends JFrame implements ActionListener {
  private JTextArea textArea;
  private JButton button1, button2, button3;
  private static final long serialVersionUID = 1L;

  public Window() {
    setSize(300, 400);
    setLayout(new FlowLayout());
    
    textArea = new JTextArea(10, 20);

    JScrollPane scrollableTextArea = new JScrollPane(this.textArea);
    scrollableTextArea.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);  
    scrollableTextArea.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);  

    add(scrollableTextArea);

    button1 = new JButton("Ajouter ligne 1");
    button1.addActionListener(this);
    add(button1);

    button2 = new JButton("Ajouter ligne 2");
    button2.addActionListener(this);
    add(button2);

    button3 = new JButton("Quitter");
    button3.addActionListener(this);
    add(button3);

    pack();
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setVisible(true);
  }

  public void actionPerformed(ActionEvent e) {
    if (e.getSource() == button1) {
      textArea.append("Ligne 1 ajoutée\n");
    } else if (e.getSource() == button2) {
      textArea.append("Ligne 2 ajoutée\n");
    } else if (e.getSource() == button3) {
      System.exit(0);
    }
  }

  public static void main(String[] args) {
    new Window();
  }
}
