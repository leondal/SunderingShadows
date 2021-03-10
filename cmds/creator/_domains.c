//      /bin/dev/_domains.c
//      from the Nightmare Mudlib
//      command to sort domain stats
//      created by Descartes of Borg 930801
//      sorting code by Cygnus@Nightmare from a pre-3.0 command

#include <std.h>
#include <dirs.h>

inherit DAEMON;

mapping domain;

int cmd_domains(string str) {
    string tmp;
    string *domains;
    mapping map_ent;
    int i, total, max;
   
    i =sizeof(domains = keys(domain = domain_stats()));
    while(i--) if(file_size(DOMAINS_DIRS+"/"+lower_case(domains[i])) != -2)
      map_delete(domain, domains[i]);
    domains = sort_array(keys(domain), "sort_stats", this_object());
    for(i=0, total=0, max = sizeof(domains); i<max; i++) 
        total += domain[domains[i]]["moves"];
    if(!total) total = 1;
    tmp = "%^BOLD%^%^GREEN%^"+mud_name()+" %^YELLOW%^Offical Domain Statistics:\n\n";
   tmp += "%^BOLD%^%^CYAN%^Name            Rank # Move   %    Cost   # Hb  Worth Arrays # Err # Obj\n";
   tmp += "%^BOLD%^%^BLACK%^--------------- ---- ------ ----- ------ ------ ----- ------ ----- -----\n";
   for (i = 0; i < sizeof(domains); i++) {
      map_ent = domain[domains[i]];
      tmp += sprintf("%%^BOLD%%^%%^BLUE%%^%-15s %4s %6d %3d.%1d %5dk %6d %5d %6d %5d %5d\n",
         domains[i],
         "(" + (i + 1) + ")",
         map_ent["moves"],
         map_ent["moves"] * 100 / total,
         map_ent["moves"] * 1000 / total % 10,
         map_ent["cost"] / 1000,
         map_ent["heart_beats"],
         map_ent["worth"],
         map_ent["array_size"],
         map_ent["errors"],
         map_ent["objects"]);
   }
   this_player()->more(explode(tmp,"\n"));
    return 1;
}

int sort_stats(string alpha, string beta) {
    mapping mapa, mapb;

    mapa = domain[alpha];
    mapb = domain[beta];
    if(mapa["moves"] == mapb["moves"]) {
        if(mapa["cost"] == mapb["cost"]) return strcmp(alpha, beta);
        else if(mapa["cost"] > mapb["cost"]) return -1;
        else return 1;
    }
    else if(mapa["moves"] > mapb["moves"]) return -1;
    else return 1;
}

void help() {
    message("help",
      "Syntax: <domains>\n\n"
      "Gives a listing of the mud domains in order of use by players.  "  
      "Roughly equivalent to the old style wizlist, except this is "
      "only for common domains.", this_player()
    );
}
