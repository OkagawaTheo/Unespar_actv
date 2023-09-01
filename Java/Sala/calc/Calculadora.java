package Java.Sala.calc;

public class Calculadora {

    double valor_atual;


    double soma(double p1,double p2){
        this.valor_atual = p1+p2;
        return this.valor_atual;
    }
    double soma(double p){
        this.valor_atual = this.valor_atual + p;
        return this.valor_atual;
    }


}
