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
public class Window extends JFrame implements ActionListener {
  private static final long serialVersionUID = 1L;
  private JTextArea textArea;
  private JButton button1, button2, btnExit;
  private JMenuBar menu;

  private void createMenuBar() {

    this.btnExit = new JButton("Exit");
    this.btnExit.setActionCommand("EXIT_BUTTON");
    this.btnExit.addActionListener(this);

    this.button1 = new JButton("Play");
    this.button1.setActionCommand("BUTTON_1");
    this.button1.addActionListener(this);

    this.button2 = new JButton("Show");
    this.button2.setActionCommand("BUTTON_2");
    this.button2.addActionListener(this);

    // this.textfield = new JTextField();

    // this.toolbar = new JToolBar();
    // this.toolbar.add(this.textfield);
    // this.toolbar.add(this.b1);
    // this.toolbar.add(this.b2);
    // this.toolbar.add(this.exitBtn);

    this.menu = new JMenuBar();
    this.menu.setOpaque(true);
    this.menu.setBackground(Color.WHITE);
		// this.menu = new JMenu("Media");
    
    // this.listMenu = new JMenu("List");

    // this.mediaMenu = new JMenuItem("Media");
    // this.mediaMenu.setActionCommand("LIST_MEDIA");
    // this.mediaMenu.addActionListener(this);
    // this.groupMenu = new JMenuItem("Group");
    // this.groupMenu.setActionCommand("LIST_GROUP");
    // this.groupMenu.addActionListener(this);

    // this.listMenu.add(this.mediaMenu);
    // this.listMenu.add(this.groupMenu);
    // this.menu.add(this.listMenu);

    // this.menubar.add(this.menu);
    // this.menubar.add(this.toolbar);
	}

  public Window() {
    setSize(300, 400);
    setLayout(new FlowLayout());
    
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

    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    pack();
    setVisible(true);

    createMenuBar();
  }

  public void actionPerformed(ActionEvent e) {
    if (e.getSource() == button1) {
      textArea.append("Ligne 1 ajoutée\n");
    } else if (e.getSource() == button2) {
      textArea.append("Ligne 2 ajoutée\n");
    } else if (e.getSource() == btnExit) {
      System.exit(0);
    }
  }

  public static void main(String[] args) {
    new Window();
  }
}
