//package gui;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.nio.file.FileSystemAlreadyExistsException;
import java.nio.file.FileSystemNotFoundException;
import java.util.ArrayList;
import java.awt.event.ActionEvent;

public class CriarConta {

	private JFrame frame;
	private JTextField txtAgencia;
	private JTextField txtNome;
	private JTextField txtConta;
	private JTextField txtSaldo;
	private JTextField txtRendimento;
	//este atributo serve para armazenar as contas criadas
	private ArrayList<Poupanca> contasPoupancas = new ArrayList<>();
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					CriarConta window = new CriarConta();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public CriarConta() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 450, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		JLabel lblNome = new JLabel("Nome:");
		lblNome.setBounds(12, 24, 70, 15);
		frame.getContentPane().add(lblNome);
		
		txtAgencia = new JTextField();
		txtAgencia.setBounds(100, 66, 114, 19);
		frame.getContentPane().add(txtAgencia);
		txtAgencia.setColumns(10);
		
		JLabel lblAgncia = new JLabel("Agência");
		lblAgncia.setBounds(12, 68, 70, 15);
		frame.getContentPane().add(lblAgncia);
		
		txtNome = new JTextField();
		txtNome.setBounds(100, 37, 114, 19);
		frame.getContentPane().add(txtNome);
		txtNome.setColumns(10);
		
		JLabel lblConta = new JLabel("Conta");
		lblConta.setBounds(12, 105, 70, 15);
		frame.getContentPane().add(lblConta);
		
		txtConta = new JTextField();
		txtConta.setBounds(100, 97, 114, 19);
		frame.getContentPane().add(txtConta);
		txtConta.setColumns(10);
		
		JLabel lblNewLabel = new JLabel("Saldo inicial");
		lblNewLabel.setBounds(12, 143, 85, 15);
		frame.getContentPane().add(lblNewLabel);
		
		txtSaldo = new JTextField();
		txtSaldo.setBounds(100, 141, 114, 19);
		frame.getContentPane().add(txtSaldo);
		txtSaldo.setColumns(10);
		
		JLabel lblRendimento = new JLabel("Rendimento");
		lblRendimento.setBounds(12, 170, 85, 15);
		frame.getContentPane().add(lblRendimento);
		
		txtRendimento = new JTextField();
		txtRendimento.setBounds(100, 168, 114, 19);
		frame.getContentPane().add(txtRendimento);
		txtRendimento.setColumns(10);
		
		JButton btnCriarConta = new JButton("Criar conta");
		btnCriarConta.addActionListener(new ActionListener() {
			
			public void actionPerformed(ActionEvent arg0) {
				
				//Este é o método que você modifica com a lógica do pressionar o click. O que acontece quando o click é pressionado?
				
				if (validarCampos(txtNome.getText(), txtAgencia.getText(), txtConta.getText(), txtSaldo.getText(), txtRendimento.getText())) {
					try{
						contasPoupancas.add(new Poupanca(txtNome.getText(), txtAgencia.getText(), Double.parseDouble(txtSaldo.getText()), Double.parseDouble(txtRendimento.getText()), 2));
						JOptionPane.showMessageDialog(null, "Conta criada com sucesso");

						for(Poupanca aux : contasPoupancas){
							if(aux.getNomeTitular().equals(txtNome.getText()) && aux.getAgencia().equals(txtAgencia.getText())){
								throw new FileSystemAlreadyExistsException();
							}
						}
					}catch (Exception exception) {
						exception.getCause();
					}
				} else {
					JOptionPane.showMessageDialog(null, "Erro: preencha todos os dados com valores válidos");
				}
			}
		});
		btnCriarConta.setBounds(159, 210, 117, 25);
		frame.getContentPane().add(btnCriarConta);
	}
	
	public boolean validarCampos(String nome, String agencia, String conta, String saldo, String rendimento) {
		if (nome.equals("") || agencia.equals("") || conta.equals("") || saldo.equals("") || rendimento.equals("")) {
			throw new FileSystemNotFoundException();
		}
		if (!saldo.matches("[0-9]+") || !rendimento.matches("[0-9]+")) {//testa se foram inseridos saldo e rendimento numéricos
			throw new FileSystemNotFoundException();
		}
		return true;
	}

}
