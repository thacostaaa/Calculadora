#include <iostream>
#include <cmath>
#include <locale.h>
#include <stdlib.h>

using namespace std;

int option = 1;

void dividerLine()
{
    cout << "======================================================" << endl;
}

void optionMenu()
{
    dividerLine();
    cout << "\nCalculadora Felipe, Nathalie e Thais\n" << endl;
    dividerLine();
    cout << "\nEscolha uma op��o:" << endl;
    cout << "1) Decimal para bin�rio" << endl;
    cout << "2) Bin�rio para decimal\n" << endl;
    dividerLine();

    cin >> option;

    // Checa se o valor digitado � v�lido
    if(cin.fail()){
        cin.clear();
        cin.ignore();
    }

    dividerLine();
}

void convertToBinary()
{
    /*
    Inicia as vari�veis que vamos utilizar. Nesse caso todas s�o do tipo "int" (n�mero inteiro)
    O output[100] quer dizer que ele � um array (lista) de n�meros inteiros que cont�m 100 "casas". Ex:
    [0,3,5,7,8,9,2,...]
    */
    int output[100], input, i=0;

    cout << "Digite um n�mero decimal:  ";

    // Pede para o usu�rio digitar o n�mero que deseja converter e salva o valor digitado na vari�vel "input"
    cin >> input;

    // Checa se o valor digitado � v�lido
    if(cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Valor inv�lido" << endl;
        dividerLine();
    } else {
        cout << input << " em bin�rio �: ";

        // Se on input for zero, o output � 0
        if (input == 0) {
            cout << 0;
        }

        // Enquanto o input for maior que zeroS
        while (input>0) {
            /*
            Adiciona a sobra da divis�o por 2 no output
            O modulus (%) retorna somente o resto de divis�o dos dois n�meros
            Ex: 4%2=0, 5%2=1, 8%3 = 2
            Nesse caso como estamos fazendo por 2, o resultado ser� sempre:
            0 quando o n�mero for par (n�o tem sobra na divis�o)
            ou
            1 quando o n�mero for �mpar (sobra 1 na divis�o)
            */
            output[i] = input%2;

            /*
            Divide o valor do input por 2
            Essa divis�o resulta em um n�mero inteiro
            Ex: 4/2=2, 5/2= 2 (2.5 � arredondado para baixo)
            */
            input = input/2;

            // Adiciona +1 ao contador para sabermos quantas casas nosso n�mero bin�rio ter�
            i++;
        }

        /*
        Mostra de traz pra frente os valores (sobras) que salvamos no "output"
        Ex: se output for [0,1,0,0,1], o loop abaixo ir� mostrar 10010 pegando da direita (�ltimo valor) para a esquerda
        */
        for(i=i-1; i>=0; i--) {
            cout << output[i];
        }

        cout << endl;

        dividerLine();
    }
}

void convertToDecimal()
{
    // Inicia as vari�veis que vamos utilizar. Nesse caso todas s�o do tipo "int" (n�mero inteiro)
    int output=0, input, i=0;

    // Pede para o usu�rio digitar o n�mero que deseja converter
    cout << "Digite um n�mero bin�rio:  ";

    // Pede para o usu�rio digitar o n�mero que deseja converter e salva o valor digitado na vari�vel "input"
    cin >> input;

    // Checa se o valor digitado � v�lido
    if(cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Valor inv�lido" << endl;
        dividerLine();
    } else {
        cout << input << " em decimal �: ";

        /*
        Enquanto o input for maior que zero repetimos o mesmo processo:
        No c�lculo o input%10 ir� sempre retornar 1 ou 0 j� que estamos dividindo um n�mero bin�ro por 10
        A sobra ser� sempre 0 quando o n�mero terminar em 0 e 1 quando o n�mero terminar em 1
        Pegamos essa sobra e multiplicamos por 2 elevado a um exponente (i) que aumenta por 1 a cada itera��o (2^0 depois 2^1 depois 2^2, etc...)
        Se por exemplo o n�mero digitado fosse 1001:
            Itera��o 1:
                pegamos a sobra de 1001/10, que � igual a 1 e multiplicamos por 2 elevado a 0 que � igual a 1, isso d� 1 (1*1) e somamos isso ao outpout.
                depois dividimos o input (1001) por 10 e aumentamos o valor o contador (i)
                input agora � 100 e j� que ele � maior que 0, repetimos o processo:
            Itera��o 2:
                pegamos a sobra de 100/10 que � igual a 0 e multiplicamos por 2 elevado a 1 (i) que � igual a 2, isso d� 0 (0*2) e somamos isso ao outpout.
                depois dividimos o input (100) por 10 e aumentamos o valor o contador (i)
                input agora � 10 e j� que ele � maior que 0, repetimos o processo:
            Itera��o 3:
                pegamos a sobra de 10/10 que � igual a 0 e multiplicamos por 2 elevado a 2 (i) que � igual a 4, isso d� 0 (0*4) e somamos isso ao outpout.
                depois dividimos o input (10) por 10 e aumentamos o valor o contador (i)
                input agora � 1 e j� que ele � maior que 0, repetimos o processo:
            Itera��o 4:
                pegamos a sobra de 1/10 que � igual a 1 e multiplicamos por 2 elevado a 3 (i) que � igual a 8, isso d� 8 (1*8) e somamos isso ao outpout.
                depois dividimos o input (1) por 10 e aumentamos o valor o contador (i)
                input agora � 0 e j� que o loop (while) s� se repete enquanto input for maior que zero, o loop se encerra
        Output ter� o valor de 1 + 0 + 0 + 8, que � 9. 1001 = 9 em decimal
        */
        while (input>0) {
            /*
            Multiplica a sobra do input/10 por 2 elevado a um poder que aumenta em 1 a cada itera��o (2^0 depois 2^1 depois 2^2, etc...)
            Adiciona esse valor no output
            */
            output = output + input%10 * pow(2, i);

            /*
            Divide o valor do input por 10
            Isso reduzir� o n�mero bin�rio em uma casa a cada itera��o at� que chegue a 0 e o loop pare de rodar
            Ex: 100101 -> 10010 -> 1001 -> 100 -> 10 -> 1 -> 0
            */
            input = input/10;

            // Adiciona +1 ao contador
            i++;
        }

        cout << output << endl;

        dividerLine();
    }
}

int main()
{
    // Resolve problema com caracteres especiais no terminal, ex: �/�/�
    setlocale(LC_ALL, "Portuguese");

    optionMenu();

    if (option==1) {
        convertToBinary();
    } else if (option==2) {
        convertToDecimal();
    }

    return 0;
}
