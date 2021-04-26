import javax.swing.JFrame;

public class Aplicacao{
    public static void main(String[] args){
        ContatoFrame contatoFrame = new ContatoFrame();

        contatoFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        contatoFrame.setSize(350, 150);
        contatoFrame.setVisible(true);
    }
}