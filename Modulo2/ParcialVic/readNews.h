//
// Created by neur0tik on 12/11/21.
//

#ifndef PARCIALVIC_READNEWS_H
#define PARCIALVIC_READNEWS_H


struct News
{
    int idNews;
    int idAgencia; // agencia de noticias
    int idAutor; // autor
    int idGenero; // genero (policial, social, econonomia,...)
    int fecha; // TAD
    int hora; // TAD
    char titulo[100];
    char foto[100];
    char contenido[4096];
}

        News* readNews()
{

}


#endif //PARCIALVIC_READNEWS_H
