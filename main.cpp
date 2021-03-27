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
    cout << "\nEscolha uma opção:" << endl;
    cout << "1) Decimal para binário" << endl;
    cout << "2) Binário para decimal\n" << endl;
    dividerLine();

    cin >> option;

    // Checa se o valor digitado é válido
    if(cin.fail()){
        cin.clear();
        cin.ignore();
    }

    dividerLine();
}

void convertToBinary()
{
    /*
    Inicia as variáveis que vamos utilizar. Nesse caso todas são do tipo "int" (número inteiro)
    O output[100] quer dizer que ele é um array (lista) de números inteiros que contém 100 "casas". Ex:
    [0,3,5,7,8,9,2,...]
    */
    int output[100], input, i=0;

    cout << "Digite um número decimal:  ";

    // Pede para o usuário digitar o número que deseja converter e salva o valor digitado na variável "input"
    cin >> input;

    // Checa se o valor digitado é válido
    if(cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Valor inválido" << endl;
        dividerLine();
    } else {
        cout << input << " em binário é: ";

        // Se on input for zero, o output é 0
        if (input == 0) {
            cout << 0;
        }

        // Enquanto o input for maior que zeroS
        while (input>0) {
            /*
            Adiciona a sobra da divisão por 2 no output
            O modulus (%) retorna somente o resto de divisão dos dois números
            Ex: 4%2=0, 5%2=1, 8%3 = 2
            Nesse caso como estamos fazendo por 2, o resultado será sempre:
            0 quando o número for par (não tem sobra na divisão)
            ou
            1 quando o número for ímpar (sobra 1 na divisão)
            */
            output[i] = input%2;

            /*
            Divide o valor do input por 2
            Essa divisão resulta em um número inteiro
            Ex: 4/2=2, 5/2= 2 (2.5 é arredondado para baixo)
            */
            input = input/2;

            // Adiciona +1 ao contador para sabermos quantas casas nosso número binário terá
            i++;
        }

        /*
        Mostra de traz pra frente os valores (sobras) que salvamos no "output"
        Ex: se output for [0,1,0,0,1], o loop abaixo irá mostrar 10010 pegando da direita (último valor) para a esquerda
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
    // Inicia as variáveis que vamos utilizar. Nesse caso todas são do tipo "int" (número inteiro)
    int output=0, input, i=0;

    // Pede para o usuário digitar o número que deseja converter
    cout << "Digite um número binário:  ";

    // Pede para o usuário digitar o número que deseja converter e salva o valor digitado na variável "input"
    cin >> input;

    // Checa se o valor digitado é válido
    if(cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Valor inválido" << endl;
        dividerLine();
    } else {
        cout << input << " em decimal é: ";

        /*
        Enquanto o input for maior que zero repetimos o mesmo processo:
        No cálculo o input%10 irá sempre retornar 1 ou 0 já que estamos dividindo um número bináro por 10
        A sobra será sempre 0 quando o número terminar em 0 e 1 quando o número terminar em 1
        Pegamos essa sobra e multiplicamos por 2 elevado a um exponente (i) que aumenta por 1 a cada iteração (2^0 depois 2^1 depois 2^2, etc...)
        Se por exemplo o número digitado fosse 1001:
            Iteração 1:
                pegamos a sobra de 1001/10, que é igual a 1 e multiplicamos por 2 elevado a 0 que é igual a 1, isso dá 1 (1*1) e somamos isso ao outpout.
                depois dividimos o input (1001) por 10 e aumentamos o valor o contador (i)
                input agora é 100 e já que ele é maior que 0, repetimos o processo:
            Iteração 2:
                pegamos a sobra de 100/10 que é igual a 0 e multiplicamos por 2 elevado a 1 (i) que é igual a 2, isso dá 0 (0*2) e somamos isso ao outpout.
                depois dividimos o input (100) por 10 e aumentamos o valor o contador (i)
                input agora é 10 e já que ele é maior que 0, repetimos o processo:
            Iteração 3:
                pegamos a sobra de 10/10 que é igual a 0 e multiplicamos por 2 elevado a 2 (i) que é igual a 4, isso dá 0 (0*4) e somamos isso ao outpout.
                depois dividimos o input (10) por 10 e aumentamos o valor o contador (i)
                input agora é 1 e já que ele é maior que 0, repetimos o processo:
            Iteração 4:
                pegamos a sobra de 1/10 que é igual a 1 e multiplicamos por 2 elevado a 3 (i) que é igual a 8, isso dá 8 (1*8) e somamos isso ao outpout.
                depois dividimos o input (1) por 10 e aumentamos o valor o contador (i)
                input agora é 0 e já que o loop (while) só se repete enquanto input for maior que zero, o loop se encerra
        Output terá o valor de 1 + 0 + 0 + 8, que é 9. 1001 = 9 em decimal
        */
        while (input>0) {
            /*
            Multiplica a sobra do input/10 por 2 elevado a um poder que aumenta em 1 a cada iteração (2^0 depois 2^1 depois 2^2, etc...)
            Adiciona esse valor no output
            */
            output = output + input%10 * pow(2, i);

            /*
            Divide o valor do input por 10
            Isso reduzirá o número binário em uma casa a cada iteração até que chegue a 0 e o loop pare de rodar
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
    // Resolve problema com caracteres especiais no terminal, ex: ç/ã/á
    setlocale(LC_ALL, "Portuguese");

    optionMenu();

    if (option==1) {
        convertToBinary();
    } else if (option==2) {
        convertToDecimal();
    }

    return 0;
}
