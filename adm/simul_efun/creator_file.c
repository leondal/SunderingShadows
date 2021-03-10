//      /adm/simul_efun/creator_file.c
//      from the Nightmare Mudlib
//      returns the name of the creator of a file, which in turn becomes
//      its uid in all cases except for backbone objects
//      created for the Nightmare security system by Descartes of Borg 930809

#include <security.h>

string creator_file(string str)
{
    string* path;

    if (!(path = explode(str, "/"))) {
        return 0;
    }
    switch (path[0]) {
    case "adm": return UID_ROOT; break;
    case "cmds":
        return (path[1] ? (path[1] == "system" ? UID_SYSTEM : UID_MUDLIB):0);
        break;
    case "std": return UID_BACKBONE; break;
    case "daemon": return UID_MUDLIB; break;
    case "obj":
        return (path[1] && path[1] == "daemon" ? UID_MUDLIB : UID_BACKBONE);
        break;
    case "arch": return UID_MUDLIB; break;
    case "high_mortal": return (path[1] ? path[1] : 0); break;
    case "realms": return (path[1] ? sprintf("%sobj", path[1]) : 0); break;
    case "d": return (path[1] ? capitalize(path[1]) : 0); break;
    default: return 0; break;
    }
}
