#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;


/** \brief Inicializa los Estados en cero
 *
 * \param lista[] EPersona recibe la estructura
 * \param largo int recibe el largo
 * \return void no retorna nada.
 *
 */
void inicializarEstado(EPersona lista[], int largo);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[],int largo);

/** \brief Agrega una persona
 *
 * \param lista[] EPersona recibe la estructura
 * \param largo int recibe el tamaño
 * \return void
 *
 */
void altaPersona(EPersona lista[], int largo);

/** \brief Elimina persona utilizando buscarPorDni
 *
 * \param lista[] EPersona Recibe la estructura
 * \param largo int Recibe el largo
 * \return void
 *
 */
void bajaPersona(EPersona lista[], int largo);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[],int largo,int dni);

/** \brief Imprime de forma ordenada por nombre
 *
 * \param lista[] EPersona Estructura
 * \param largo int Largo del Array
 * \return void
 *
 */
void imprimirNombre(EPersona lista[],int largo);

/** \brief Grafico de barras de distintas edades(>18;19 a 35;35<)
 *
 * \param lista[] EPersona Recibe la estructura
 * \param largo int Recibe el largo de la misma
 * \return void
 *
 */
void imprimirGrafica(EPersona lista[],int largo);

#endif // FUNCIONES_H_INCLUDED
