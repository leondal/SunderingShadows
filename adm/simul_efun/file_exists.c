//      /adm/simul_efun/file_exists.c
//      from the Ngghtmare mudlib
//      returns true if there be such a file
//      created by Descartes of Borg 18 april 1993

#include <config.h>

int file_exists(string str) {
    seteuid(geteuid(previous_object()));
    return (file_size(str) > -1);
}
