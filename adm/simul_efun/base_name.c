//	/adm/simul_efun/base_name.c
//	from the Nightmare mudlib
//	returns the name of the file of an object without extensions
//	based on the simul_efun originally by Truilkan@Basis
//	created by Descartes of Borg 22 december 1992

string base_name(object ob) {
    string name, base;
    int borg;

      if(!objectp(ob)) return "Not complete object";     
    name = file_name(ob);
    if(sscanf(name, "%s#%d", base, borg) ==2) return base;
    else return name;
}
