#include <std.h>
#define BASE "/d/islands/dinosaur/rooms/"

#define TREXNUM 1
#define ANKYNUM 2
#define DEINONUM 4
#define DIPLONUM 2
#define LAMBEONUM 6
#define MONGNUM 3
#define MONGTWONUM 3
#define PTERANUM 4
#define STEGONUM 2
#define TRICNUM 2
#define MAXNUMS ({TREXNUM, ANKYNUM, DEINONUM, DIPLONUM, LAMBEONUM, MONGNUM, MONGTWONUM, PTERANUM, STEGONUM, TRICNUM})
#define TYPES ({"trex", "anky", "deino", "diplo", "lambeo", "mong", "mongtwo", "ptera", "stego", "tric"})

inherit DAEMON;
int healer = 0;
mapping mobs;
int started = 0;

void check_healer();
void dead_healer();
string query_dino_file(string str);
object random_room();
void place_em(string mon, object room, int amt);
string pick_dino();
int amount(string str);
void dino_party(object room);

void clean_up() {return 1;}

void check_healer(){
    string room, *rmlist;
    object ob, ob2;

    ob = random_room();
    if(!healer){
      healer = 1;
      new("/d/islands/dinosaur/obj/tent.c")->move(ob);
      find_object_or_load("/d/islands/dinosaur/healer.c")->remove_exit("out");
      find_object_or_load("/d/islands/dinosaur/healer.c")->add_exit(base_name(ob), "out");
      new("/d/islands/dinosaur/mon/tent_guard.c")->move(ob);
    }
}

void dead_healer(){
    healer = 0;
}

string query_dino_file(string str){
    switch(str){
      case "trex": return "/d/islands/dinosaur/mon/tyrano.c";
      case "anky": return "/d/islands/dinosaur/mon/anky.c";
      case "deino": return "/d/islands/dinosaur/mon/deino.c";
      case "diplo": return "/d/islands/dinosaur/mon/diplo.c";
      case "lambeo": return "/d/islands/dinosaur/mon/lambeo.c";
      case "mong": return "/d/islands/dinosaur/mon/mong.c";
      case "mongtwo": return "/d/islands/dinosaur/mon/mong2.c";
      case "ptera": return "/d/islands/dinosaur/mon/ptera.c";
      case "stego": return "/d/islands/dinosaur/mon/stego.c";
      case "tric": return "/d/islands/dinosaur/mon/tric.c";
    }
    return "";
}

object random_room(){
    string *rmlist, rm;

    rmlist = get_dir(BASE);
    rmlist -= ({"testlongfile"});
    rm = rmlist[random(sizeof(rmlist))];
    rm = BASE + rm;
    return find_object_or_load(rm);
}

void place_em(string mon, object room, int amt){
    int i;
    for(i=0;i<amt;i++)
      new(query_dino_file(mon))->move(room);
}

string pick_dino(){
    switch(random(100)){
      case 0..4: return "trex";
      case 5..14: return "anky";
      case 15..27: return "deino";
      case 28..32: return "diplo";
      case 33..57: return "lambeo";
      case 58..65: return "mong";
      case 66..73: return "mongtwo";
      case 74..83: return "ptera";
      case 84..91: return "stego";
      case 92..99: return "tric";
    }
    return "lambeo";
}

int amount(string str){
    switch(str){
      case "trex": return random(TREXNUM)+1;
      case "anky": return random(ANKYNUM)+1;
      case "deino": return random(DEINONUM)+1;
      case "diplo": return random(DIPLONUM)+1;
      case "lambeo": return random(LAMBEONUM)+1;
      case "mong": return random(MONGNUM)+1;
      case "mongtwo": return random(MONGTWONUM)+1;
      case "ptera": return random(PTERANUM)+1;
      case "stego": return random(STEGONUM)+1;
      case "tric": return random(TRICNUM)+1;
    }
    return 1;
}

void dino_party(object room){
    string str;

    str = pick_dino();
    place_em(str, room, amount(str));
    check_healer();
    if(!random(4)){
      str = pick_dino();
      place_em(str, random_room(), amount(str));
    }
}
