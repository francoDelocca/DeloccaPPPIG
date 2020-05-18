#include <stdio.h>
#include <stdlib.h>



struct eNotebook{
    int id;
    char marca[30];
    char procesador[30];
    float precio;
};

int contarCaracteres(char nombre[], char letra);
float aplicarDescuento(float precio);
int mostrarNotebooks(struct eNotebook notebooks[], int TAM);
int ordenarNotebooks(struct eNotebook notebooks[], int TAM);

int main()
{
    char nombre[30];
    char letra;
    float precio;
    int TAM = 4;

    struct eNotebook notebooks[4] = {
        {
            0001, "Asus", "Intel", 3000
        },
        {
            0002, "Lenovo", "AMD", 5000
        },
        {
            0003, "HP", "AMD", 8000
        },
        {
            0004, "Lenovo", "Intel", 8000
        }
    };

    printf("Ingrese precio para aplicar descuento: ");
    scanf("%f", &precio);

    printf("Ingrese nombre para saber los caracteres que se repiten: ");
    scanf("%s", &nombre);
    fflush(stdin);

    printf("Ingrese el caracter a buscar: ");
    scanf("%c", &letra);
    fflush(stdin);

    printf("1. El precio con descuento es %f \n\n", aplicarDescuento(precio));
    printf("2. El caracter %c se repite %d veces en %s\n\n",letra, contarCaracteres(nombre, letra), nombre);

    mostrarNotebooks(notebooks, TAM);

}

int mostrarNotebooks(struct eNotebook notebooks[], int TAM){
    ordenarNotebooks(notebooks, TAM);
    for(int i = 0; i < TAM; i++){
        printf("%d      %s      %s      %5.2f\n\n", notebooks[i].id, notebooks[i].procesador, notebooks[i].marca, notebooks[i].precio);
    }
    return 0;
}

int ordenarNotebooks(struct eNotebook notebooks[], int TAM){
    struct eNotebook auxMarca;
    struct eNotebook auxPrecio;

    for(int i = 0; i < TAM ; i++){

        for(int j = 0; j < TAM; j++){

            if(strcmp(notebooks[i].marca, notebooks[j].marca) <0){
                auxMarca = notebooks[i];
                notebooks[i] = notebooks[j];
                notebooks[j] = auxMarca;

                if(strcmp(notebooks[i].marca, notebooks[j].marca) == 0 && notebooks[i].precio > notebooks[j].precio){
                    auxPrecio = notebooks[i];
                    notebooks[i] = notebooks[j];
                    notebooks[j] = auxPrecio;
                }
            }
        }
    }

    return 0;
}

float aplicarDescuento(float precio){
    float descuento;
    float porcentaje = 0.95;

    descuento = precio * porcentaje;

    return descuento;
}

int contarCaracteres(char nombre[], char letra){
    int contador = 0;
    int i = 0;
    while(nombre[i] != '\0'){
        if(nombre[i]==letra){
            contador++;
        }
        i++;
    }

    return contador;
}




