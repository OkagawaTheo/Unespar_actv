import javax.swing.*;
import java.util.Scanner;

public class Produtos {
    Scanner s = new Scanner(System.in);
    
    double valorProduto;
    double valorComDesconto;
    String nomeProduto;

    String catchNomeProduto(){
        System.out.println("Digite o nome do produto: ");
        this.nomeProduto = s.nextLine();

        return nomeProduto;
    }
    double catchValor(){
        System.out.println("Digite o valor do produto: ");
        this.valorProduto = s.nextFloat();

        return valorProduto;
    }
    
    double calcDesconto(){
       if (this.valorProduto >= 50 && this.valorProduto < 200){
        this.valorComDesconto = this.valorProduto - (this.valorProduto*0.05); //desconto 5
       }
       else if (this.valorProduto >= 200 && this.valorProduto < 500){
        this.valorComDesconto = this.valorProduto - (this.valorProduto*0.06); //desconto 6
       }
       else if (this.valorProduto >= 500 && this.valorProduto < 1000){
        this.valorComDesconto = this.valorProduto - (this.valorProduto*0.07); //desconto 7
       }
       else if (this.valorProduto >= 1000){
        this.valorComDesconto = this.valorProduto - (this.valorProduto*0.08); //desconto 8
       }
        return valorComDesconto;
    }

    void showMessage(){
        JOptionPane.showMessageDialog(null,"Nome do Produto: " + this.nomeProduto + "\n Valor antigo: " + this.valorProduto + "\nValor com desconto: " + this.valorComDesconto);
    }
    
}
//>.<