#include <std.h>
#include <dirs.h>

inherit DAEMON;

mapping author;

int cmd_realms(string str) {
    string tmp;
    string *authors;
    mapping map_ent;
    int i, total, max;
   
    i =sizeof(authors = keys(author = author_stats()));
    while(i--) if(file_size(REALMS_DIRS+"/"+lower_case(authors[i])) != -2)
      map_delete(author, authors[i]);
    authors = sort_array(keys(author), "sort_stats", this_object());
    for(i=0, total=0, max = sizeof(authors); i<max; i++) 
        total += author[authors[i]]["moves"];
    if(!total) total = 1;
    tmp = mud_name()+" Offical Realm Statistics:\n\n";
   tmp += "Name            Rank # Move   %    Cost   # Hb  Worth Arrays # Err # Obj\n";
   tmp += "--------------- ---- ------ ----- ------ ------ ----- ------ ----- -----\n";
   for (i = 0; i < sizeof(authors); i++) {
      map_ent = author[authors[i]];
      tmp += sprintf("%-15s %4s %6d %3d.%1d %5dk %6d %5d %6d %5d %5d\n",
         authors[i],
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

    mapa = author[alpha];
    mapb = author[beta];
    if(mapa["moves"] == mapb["moves"]) {
        if(mapa["cost"] == mapb["cost"]) return strcmp(alpha, beta);
        else if(mapa["cost"] > mapb["cost"]) return -1;
        else return 1;
    }
    else if(mapa["moves"] > mapb["moves"]) return -1;
    else return 1;
}

void help() {
    write("Syntax: <realms>\n\n"
      "Gives a listing of mud realms in order of use by players.\n"
      "This command is roughly equivalent to the old wizlist command.\n"
    );
}
