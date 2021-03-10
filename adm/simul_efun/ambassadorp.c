//      /adm/simul_efun/ambassadorp.c
//      from the Nightmare Mudlib
//      returns true for ambassadors
//      created by Descartes of Borg 930809

int ambassadorp(object ob) { return member_group(geteuid(ob), "ambassador"); }
