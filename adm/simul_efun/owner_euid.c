/*    /adm/simul_efun/owner_euid.c
 *    from the Nightmare Mudlib 3.2
 *    returns the euid of the owner of an object
 *    created by Descartes of Borg 940129
 */

string owner_euid(mixed val) {
    string euid, ext;
    int x;
    if(objectp(val)) val = geteuid(val);
    else if(!stringp(val)) error("Bad argument 1 to owner_euid().\n");
    if((x = strlen(val)) < 4) return val;
    euid = val[0..(x-4)];
    ext = val[(x-3)..(x-1)];
    if(ext != "obj") return val;
    else return euid;
}
