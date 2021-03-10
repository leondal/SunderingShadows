//      /adm/simul_efun/alignment_ok.c
//      from the Nightmare mudlib
//      checks to see if the class member is obeying class alignment
//      created by Descartes of Borg 1 june 1993

int alignment_ok(object ob) {
    string myClass;
    int al;

    if((int)ob->query_level() == 1) return 1;
    myClass = (string)ob->query_class();
    if(!myClass) return 1;
    al = (int)ob->query_alignment();
    switch(myClass) {
        case "monk": return (al > 200);
        case "cleric": return (al > 0);
        case "kataan": return (al < -200);
        default: return 1;
    }
}
