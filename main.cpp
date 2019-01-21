#include <stdio.h>
#define dim 5

struct Coche
{
    float Kilometraje;
    float Valor;
};

struct Barco
{
    float Longitud;
    float Tonelaje;
    float Valor;
};

struct Avion
{
    int N_motores;
    int N_asientos;
    float Recorrido;
    float Valor;
};

struct Vehiculo
{
    Coche V1;
    Barco V2;
    Avion V3;
};

struct Cliente
{
    Vehiculo Alquiler;
    char nombre[20];
};

void menu()
{
    printf("\n---MENU PRINCIPAL---");
    printf("\nA. Alquilar Avion");
    printf("\nB. Alquilar Barco");
    printf("\nC. Alquilar Coche");

    printf("\nEscoja una opcion: ");
}

void menurepor()
{
    printf("\n---MENU PRINCIPAL---");
    printf("\nA. Alquilar Avion");
    printf("\nB. Alquilar Barco");
    printf("\nC. Alquilar Coche");
    printf("\nD. Imprimir reporte");

    printf("\nEscoja una opcion: ");
}

float validacionfl(float val)
{
    while(val<=0)
    {
        printf("\nValor no valido! Ingrese de nuevo: ");
        scanf("%f",&val);
    }

    return(val);
}

int validacionint(int val)
{
    while(val<1)
    {
        printf("\nValor no valido! Ingrese de nuevo: ");
        scanf("%d",&val);
    }

    return(val);
}

//COCHE


void ingresocoche(Cliente *Usuario,int letra,int base)
{
    float x,proceso;

    fflush(stdin);
    printf("\nIngrese el nombre del cliente: ");
    scanf("%s",&Usuario->nombre);

    printf("\nNombre ingresado: %s",Usuario->nombre);

    printf("\nIngrese el kilometraje: ");
    scanf("%f",&x);
    x=validacionfl(x);
    Usuario->Alquiler.V1.Kilometraje=x;

    printf("\nKilometraje ingresado: %.2f",Usuario->Alquiler.V1.Kilometraje);

    printf("\nCOSTO DEL ALQUILER: ");
    proceso=(Usuario->Alquiler.V1.Kilometraje)*base;
    printf("%.2f\n",proceso);

    Usuario->Alquiler.V1.Valor=proceso;


}

//BARCO

void ingresobarco(Cliente *Usuario,int letra,int base)
{
    float x,proceso;

    fflush(stdin);
    printf("\nIngrese el nombre del cliente: ");
    scanf("%s",&Usuario->nombre);

    printf("\nNombre ingresado: %s",Usuario->nombre);

    printf("\nIngrese la longitud: ");
    scanf("%f",&x);
    x=validacionfl(x);
    Usuario->Alquiler.V2.Longitud=x;

    printf("\nIngrese el tonelaje: ");
    scanf("%f",&x);
    x=validacionfl(x);
    Usuario->Alquiler.V2.Tonelaje=x;

    proceso=(Usuario->Alquiler.V2.Longitud)*base*(Usuario->Alquiler.V2.Tonelaje);
    Usuario->Alquiler.V2.Valor=proceso;
    printf("\nCOSTO DE ALQUILER: %.2f\n",Usuario->Alquiler.V2.Valor);

}

//AVION

void ingresoavion(Cliente *Usuario,int letra,int base)
{
    int y;
    float x,proceso;

    fflush(stdin);
    printf("\nIngrese el nombre del cliente: ");
    scanf("%s",&Usuario->nombre);

    printf("\nNombre ingresado: %s",Usuario->nombre);

    printf("\nIngrese el numero de motores: ");
    scanf("%d",&y);
    y=validacionint(y);
    Usuario->Alquiler.V3.N_motores=y;

    printf("\nIngrese el numero de asientos: ");
    scanf("%d",&y);
    y=validacionint(y);
    Usuario->Alquiler.V3.N_asientos=y;

    printf("\nIngrese el valor de recorrido: ");
    scanf("%f",&x);
    x=validacionfl(x);
    Usuario->Alquiler.V3.Recorrido=x;

    proceso=((Usuario->Alquiler.V3.N_motores)+(Usuario->Alquiler.V3.N_asientos))*base*(Usuario->Alquiler.V3.Recorrido);
    Usuario->Alquiler.V3.Valor=proceso;
    printf("\nCOSTO DEL ALQUILER: %.2f",Usuario->Alquiler.V3.Valor);
}


//VALIDACION BUCLE

char valbucle(char bucle)
{
    while((bucle!='S'&&bucle!='s')&&(bucle!='N'&&bucle!='n'))
    {
        printf("\nCaracter no valido! Ingrese uno correcto: ");
        scanf("\n%c",&bucle);
    }

    return(bucle);
}


int main()
{
    int bc=5,bb=15,ba=25, i=0,j;
    char opc;
    char bucle='S';
    int tipo[dim];
    Cliente usuario[dim];

    for(j=0;j<dim;j++)
        tipo[j]=0;

    do
    {
    if(i==dim)
    {
        printf("\nYa no se pueden ingresar mas datos al sistema...");
        printf("\n---A continuacion, se desplegaran todos los datos ingresados al sistema---");

        for(int k=0;k<dim;k++)
                {
                    if(tipo[k]!=0)
                    {
                        if(tipo[k]==3)
                        {
                            printf("\n---Usuario %d---",k+1);
                            printf("\nTransporte: COCHE");
                            printf("\nNombre: %s",usuario[k].nombre);
                            printf("\nKilometraje: %.2f",usuario[k].Alquiler.V1.Kilometraje);
                            printf("\nCosto del alquiler: %.2f\n",usuario[k].Alquiler.V1.Valor);

                        }

                        if(tipo[k]==2)
                        {
                            printf("\n---Usuario %d---",k+1);
                            printf("\nTransporte: BARCO");
                            printf("\nNombre: %s",usuario[k].nombre);
                            printf("\nLongitud: %.2f",usuario[k].Alquiler.V2.Longitud);
                            printf("\nTonelaje: %.2f",usuario[k].Alquiler.V2.Tonelaje);
                            printf("\nCosto del alquiler: %.2f\n",usuario[k].Alquiler.V2.Valor);

                        }

                        if(tipo[k]==1)
                        {
                            printf("\n---Usuario %d---",k+1);
                            printf("\nTransporte: AVION");
                            printf("\nNombre: %s",usuario[k].nombre);
                            printf("\nNumero de motores: %d",usuario[k].Alquiler.V3.N_motores);
                            printf("\nNumero de asientos: %d",usuario[k].Alquiler.V3.N_asientos);
                            printf("\nRecorrido: %.2f",usuario[k].Alquiler.V3.Recorrido);
                            printf("\nCosto del alquiler: %.2f\n",usuario[k].Alquiler.V3.Valor);


                        }
                    }
                }
        bucle='N';
    }
    else
    {
        if(i==0)
        {
            menu();
            scanf("\n%c",&opc);

            switch(opc)
            {
            case 'C':case 'c':
                tipo[i]=3;
                ingresocoche(&usuario[i],i,bc);
                i++;
                printf("\nDesea continuar? S/N: ");
                scanf("\n%c",&bucle);
                bucle=valbucle(bucle);
                break;

            case 'B':case 'b':
                tipo[i]=2;
                ingresobarco(&usuario[i],i,bb);
                i++;
                printf("\nDesea continuar? S/N: ");
                scanf("\n%c",&bucle);
                bucle=valbucle(bucle);
                break;

            case 'A':case 'a':
                tipo[i]=1;
                ingresoavion(&usuario[i],i,ba);
                i++;
                printf("\nDesea continuar? S/N: ");
                scanf("\n%c",&bucle);
                bucle=valbucle(bucle);
                break;

            default:
                printf("\nLa opcion ingresada es incorrecta. Vuelva a intentar...\n\n");
            }

        }
        else
        {
            menurepor();
            scanf("\n%c",&opc);

            switch(opc)
            {
            case 'C':case 'c':
                tipo[i]=3;
                ingresocoche(&usuario[i],i,bc);
                i++;
                printf("\nDesea continuar? S/N: ");
                scanf("\n%c",&bucle);
                bucle=valbucle(bucle);
                break;

            case 'B':case 'b':
                tipo[i]=2;
                ingresobarco(&usuario[i],i,bb);
                i++;
                printf("\nDesea continuar? S/N: ");
                scanf("\n%c",&bucle);
                bucle=valbucle(bucle);
                break;

            case 'A':case 'a':
                tipo[i]=1;
                ingresoavion(&usuario[i],i,ba);
                i++;
                printf("\nDesea continuar? S/N: ");
                scanf("\n%c",&bucle);
                bucle=valbucle(bucle);
                break;

            case 'D':case 'd':
                for(int k=0;k<dim;k++)
                {
                    if(tipo[k]!=0)
                    {
                        if(tipo[k]==3)
                        {
                            printf("\n---Usuario %d---",k+1);
                            printf("\nTransporte: COCHE");
                            printf("\nNombre: %s",usuario[k].nombre);
                            printf("\nKilometraje: %.2f",usuario[k].Alquiler.V1.Kilometraje);
                            printf("\nCosto del alquiler: %.2f\n",usuario[k].Alquiler.V1.Valor);

                        }

                        if(tipo[k]==2)
                        {
                            printf("\n---Usuario %d---",k+1);
                            printf("\nTransporte: BARCO");
                            printf("\nNombre: %s",usuario[k].nombre);
                            printf("\nLongitud: %.2f",usuario[k].Alquiler.V2.Longitud);
                            printf("\nTonelaje: %.2f",usuario[k].Alquiler.V2.Tonelaje);
                            printf("\nCosto del alquiler: %.2f\n",usuario[k].Alquiler.V2.Valor);
                        }

                        if(tipo[k]==1)
                        {
                            printf("\n---Usuario %d---",k+1);
                            printf("\nTransporte: AVION");
                            printf("\nNombre: %s",usuario[k].nombre);
                            printf("\nNumero de motores: %d",usuario[k].Alquiler.V3.N_motores);
                            printf("\nNumero de asientos: %d",usuario[k].Alquiler.V3.N_asientos);
                            printf("\nRecorrido: %.2f",usuario[k].Alquiler.V3.Recorrido);
                            printf("\nCosto del alquiler: %.2f\n",usuario[k].Alquiler.V3.Valor);


                        }
                    }
                    else
                        ;
                }

                break;

            default:
                printf("\nLa opcion ingresada es incorrecta. Vuelva a intentar...\n\n");
            }
        }
    }

    }while(bucle=='S'||bucle=='s');


    return 0;
}
