import javax.swing.*;
import java.awt.*;

public class ContatoFrame extends JFrame{

    public ContatoFrame(){
        super("Poupex");
        criarFormulario();
    }

    private void criarFormulario(){
        setLayout(new BorderLayout());

        JPanel panelDados = new JPanel();
        panelDados.setLayout(new BorderLayout());

        JPanel panelJuros = new JPanel();
        panelJuros.setLayout(new BorderLayout());

        JLabel jurosLabel = new JLabel("Juros ao mes %:");
        JTextField jurosField = new JTextField(10);

        panelJuros.add(jurosLabel, BorderLayout.WEST);
        panelJuros.add(jurosField, BorderLayout.EAST);

        JPanel panelAnos = new JPanel();
        panelAnos.setLayout(new BorderLayout());

        JLabel anosLabel = new JLabel("Num. de anos:");
        JTextField anosField = new JTextField(10);

        panelAnos.add(anosLabel, BorderLayout.WEST);
        panelAnos.add(anosField, BorderLayout.EAST);

        JPanel panelDeposito = new JPanel();
        panelDeposito.setLayout(new BorderLayout());

        JLabel depositoLabel = new JLabel("Depósito mensal R$:");
        JTextField depositoField = new JTextField(10);

        panelDeposito.add(depositoLabel, BorderLayout.WEST);
        panelDeposito.add(depositoField, BorderLayout.EAST);

        panelDados.add(panelJuros, BorderLayout.NORTH);
        panelDados.add(panelAnos, BorderLayout.CENTER);
        panelDados.add(panelDeposito, BorderLayout.SOUTH);

        //total
        JPanel panelTotal = new JPanel();
        panelTotal.setLayout(new BorderLayout());

        JLabel totalLabel = new JLabel("Total poupado R$:");
        //JTextField totalField = new JTextField(10);

        panelTotal.add(totalLabel, BorderLayout.WEST);
        //panelDeposito.add(totalField, BorderLayout.EAST);

        //botao
        JPanel panelBotoes = new JPanel();
        panelBotoes.setLayout(new BorderLayout());

        JButton botaoOK = new JButton("OK");

        panelBotoes.add(botaoOK, BorderLayout.EAST);

        add(panelDados, BorderLayout.NORTH);
        add(panelTotal, BorderLayout.CENTER);
        add(panelBotoes, BorderLayout.SOUTH);
    }
}