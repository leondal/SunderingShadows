//	/adm/simul_efun/interact.c
//	from the Nightmare mudlib
//	searches a string for a given substring 
//	created by Descartes of Borg 03 february 1993

int interact(string substr, string str) {
    string a, b;
  
    if(!str) return 0;
    if(!substr) return 0;
    if(sscanf(str, "%s"+substr+"%s", a, b) ==2) return 1;
    if(sscanf(str, substr+"%s", a) ==1) return 1;
    if(sscanf(str, "%s"+substr, a) == 1) return 1;
    return 0;
}
