//	/adm/simul_efun/member_group.c
//	from the Nightmare mudlib
//	to tell if someone is a member of a group
//	created by Descartes of Borg 22 december 1992

#include <config.h>

int member_group(string user, string grp) {
    return (int)master()->query_member_group(user, grp);
}
