#include <std.h>
#include <security.h>

inherit DAEMON;

/**
 * @file
 * @brief Lowgame collector items
 */


#define COLORS ({"%^RED%^red", "%^BLUE%^blue","%^CYAN%^cyan", "%^GREEN%^green", "%^MAGENTA%^magenta", "%^YELLOW%^yellow","white","%^ORANGE%^orange","%^BOLD%^%^BLACK%^black"})

#define OBJECTS ({"chalice","parchment","tunic","boots","cup","bowl", "knife", "scroll", "tablet","hat","tome","rod","statue","figurine","amulet", "talisman", "slippers", "flask","candle","mirror","rug","brooch","egg","scarf", "sphere", "cube", "stone", "crown", "amulet"})

#define DESCRIPTS ({"brilliance","fortune","doom","power","evil","good", "neutrality", "the sun","the earth","the moon","the land","the sky", "force", "darkness", "light", "control", "destiny", "fortitude", "cowardice","death","health", "life", "shielding", "the universe", "horror", "beauty", "comeliness","humility","pride", "truth", "lies", "weakness", "strength", "nature", "terror", "fear", "courage", "wonder",})

#define SAVE_QUESTS "/daemon/save/quests_low"

#define LOW ({"/d/koenig/streams/", "/d/koenig/village/",  "/d/shadow/room/kildare/rooms/cave", "/d/shadow/room/forest/road", "/d/shadow/room/farm/room/cellar", "/d/shadow/room/farm/room/farm", "/d/koenig/fields/room/"})

#define LMID1 ({"/d/shadow/room/goblin/rooms/tower", "/d/shadow/room/mountain/", "/d/shadow/room/mountain/tunnel", "/d/shadow/room/cave/", "/d/darkwood/camps/rooms/town/", "/d/shadow/room/kildare/rooms/roads/", "/d/shadow/room/meadows/"  })

#define LMID2 ({"/d/koenig/town/t", "/d/koenig/town/crypt",  "/d/tharis/conforest/rooms/", "/d/shadow/room/cave/cavern", "/d/koenig/caves/", "/d/shadow/room/kildare/rooms/ptrail", "/d/koenig/streams/cr", "/d/darkwood/yntala/rooms/meadow", "/d/shadow/city/room/sewer"})

#define HMID1 ({ "/d/shadow/room/kildare/rooms/nest",  "/d/darkwood/camps/rooms/orcamp/", "/d/darkwood/yntala/rooms/forest1", "/d/darkwood/yntala/rooms/forest2", "/d/darkwood/yntala/rooms/uw", "/d/shadow/room/feyren/rooms/" })

#define GEN_LIST ({ "Town of Muileann", "An underground crypt", "Darkwood Forest", "Meadowlands", "Rapidly flowing stream", "Ruins of Koenig", "A rocky path", "Cornfield", "Echoes Mountains", "Dragon's Den Caverns", "Twisting Mountain Trail", "Kildare Glen", "Farmyard", "Elven village", "Abandoned, ransacked village", "Goblin Stronghold", "A small cave", "Bestial nest" })

#define AREAS ({LOW, LMID1, LMID1, LMID2, HMID1})

#define AREA_VALUE ({16000, 20000, 24000, 28000, 32000})

#define MAXSIZE 30

#define QOBJECT "/d/common/obj/misc/qobject.c"

#define OBSTORE "/d/save/quests/"+

#define ANTIOCH "/d/antioch/"+
#define LAERAD "/d/laerad/"+
#define DEKU "/d/deku/"+
#define DROW "/d/dagger/drow/"+
#define GOBLIN "/d/shadow/room/goblin/"+
#define D_MARSH "/d/dagger/marsh/"+
#define ISLANDS "/d/islands/"+
#define THARIS "/d/tharis/"+
#define AZHA "/d/azha/"+
#define KOENIG "/d/koenig/town/"+
#define SHADOW "/d/shadow/"+

#define MONSTERS ([\
                        GOBLIN "mon/king.c":20600,\
                        GOBLIN "mon/king.c":20600,\
                        GOBLIN "mon/rogue.c":15100,\
                        GOBLIN "mon/gobass.c":15100,\
                        KOENIG "mon/thess.c":15100,\
                        KOENIG "mon/magglerak.c": 18000,\
                        KOENIG "mon/cryptkeeper.c": 20600,\
                        KOENIG "mon/crysmon1.c":18000,\
                        KOENIG "mon/gentleman.c":22800,\
                        KOENIG "mon/donner.c":18000,\
                        KOENIG "mon/headcook.c":18000,\
                        KOENIG "mon/decapus.c":17100,\
                        KOENIG "mon/mansnake.c":17100,\
                        KOENIG "mon/concubine.c":18000,\
                        KOENIG "mon/butler.c":17100,\
                        KOENIG "mon/welemental.c":19100,\
                        SHADOW "room/mountain/mons/koboldf.c":18500,\
                        SHADOW "room/mountain/mons/koboldf.c":18500,\
                        SHADOW "room/kildare/mon/peryking.c":19500,\
                        SHADOW "room/kildare/mon/peryking.c":19500,\
                        SHADOW "room/mountain/mons/ogreking.c":19100,\
                        SHADOW "room/mountain/mons/grakulan.c":19500,\
                        "/d/darkwood/camps/mon/gore.c":19500,\
                        SHADOW "room/feyren/mon/ashilla.c": 22800,\
                        SHADOW "room/feyren/mon/feyren.c": 22800,\
                        SHADOW "room/feyren/mon/ahyriquel.c":22800,\
                        THARIS "conforest/mons/orcchief.c":19100,\
                        SHADOW "room/farm/mon/sea_hag.c":17100,\
                        SHADOW "room/farm/mon/hildegard.c":17100,\
                        "/d/koenig/mon/ogremage.c":18000,\
                        ])

mapping __Quests, __Rooms, __Monsters;
mapping __Removal;

void test_quests();

string query_name() { return "Low random quests daemon"; }
string query_short() { return "Low random quests daemon"; }
protected void SAVE(){
  seteuid(UID_DAEMONSAVE);
  save_object(SAVE_QUESTS);
  seteuid(getuid());
}

void create(){
   ::create();
   __Quests = ([]);
   __Monsters = ([]);
   __Rooms = ([]);
   __Removal = ([]);
   seteuid(UID_DAEMONSAVE);
   restore_object(SAVE_QUESTS);
   if(!__Quests)
      __Quests = ([]);
   if(!__Monsters)
      __Monsters = ([]);
   if(!__Rooms)
      __Rooms = ([]);
   if(!__Removal)
      __Removal == ([]);
   SAVE();
   test_quests();
   set_heart_beat(30);
}

int query_generic_list() {
   return GEN_LIST;
}

string makeObject(){
   int i,j,k;
   string hold;

   i = random(sizeof(COLORS));
   j = random(sizeof(OBJECTS));
   k = random(sizeof(DESCRIPTS));

   hold = COLORS[i]+" "+OBJECTS[j]+" of "+DESCRIPTS[k]+"%^RESET%^";
   return hold;
}

void newMon(){
   string name, file, short;
   int exp, date, reDate;

   name = makeObject();
   while (member_array(name, keys(__Quests)) != -1) {
      name = makeObject();
   }
   file = (keys(MONSTERS))[random(sizeof(keys(MONSTERS)))];

   while (member_array(file, keys(__Monsters)) != -1) {
      file = keys(MONSTERS)[random(sizeof(keys(MONSTERS)))];
   }
   date = time();
// lowering the adder to half to narrow range for better reasonableness *Styx* 6/12/05
   exp = MONSTERS[file]+(random(MONSTERS[file])/2);
   exp = exp * (2 + random(2));
   __Monsters[file] = ({date,name});

   reDate = date+86400+random(86400*1);
   while(__Removal[reDate])
   {
        reDate = date+86400+random(86400*5);
        continue;
   }

   if(file->query_invis()) {
      file->set_invis();
      short= file->query_short();
      file->set_invis();
   } else
      short = file->query_short();

   __Quests[name] = ({"monster",file,exp,short, reDate});
   __Removal[reDate] = name;
   __Monsters[file] = ({date, name, 0});

if(!file_exists(OBSTORE date+".c"))
   write_file(OBSTORE date+".c","inherit \""+QOBJECT+"\";");
   SAVE();
}

string *NotValidDir()
{
	int x;
	string *tmp, *tmp2, *tmp3;
	tmp = ({});
	tmp2 = LOW + LMID1 + LMID2 + HMID1;
	for(x = 0;x < sizeof(tmp2);x++)
	{
		tmp3 = get_dir(tmp2[x] + "*.c");
		if(!sizeof(tmp3))
		{
			tmp += ({tmp2[x]});
			continue;
		}
		continue;
	}
	return tmp;
}

void newRoom(){
   string name, file, dir, *files;
   int i,exp, date, reDate;
   int flag;

   i= random(4);
   dir = AREAS[i][random(sizeof(AREAS[i]))];
   files = get_dir(dir+"*.c");
   if(sizeof(files)==1 && member_array(files[0], keys(__Rooms)) != -1)
       return;
// lowering the adder to half to narrow range for better reasonableness *Styx* 6/12/05
   exp = AREA_VALUE[i] + (random(AREA_VALUE[i])/2);
   name = makeObject();

   while (member_array(name, keys(__Quests)) != -1) {
      name = makeObject();
   }
// adding check and log for bad file listing *Styx* 1/4/04, last change 12/13/03
   if(!sizeof(files)) {
      seteuid(UID_LOG);
      seteuid(getuid());
      return;
   }

   file =  files[random(sizeof(files))];

   flag = 0;
   while (member_array(file, keys(__Rooms)) != -1 ||
          member_array(file, values(map(__Quests,(:$2[1]:)))) != -1)
   {
      file =  files[random(sizeof(files))];
        flag++;
        if(flag > 20) return; // failsafe
   }

   while(dir[strlen(dir)-1] != '/'){
      dir = dir[0..strlen(dir)-2];
   }
   file = dir+file;
   date = time();

   reDate = date+86400+random(86400*5);
   while(__Removal[reDate])
     reDate = date+86400+random(86400*5);

   if(member_array(file, values(map(__Quests,(:$2[1]:)))) != -1)
       return;

   __Rooms[file] = ({date,name,0});
   __Removal[reDate] = name;
   __Quests[name] = ({"room",file,exp,file->query_short(), reDate});
if(!file_exists(OBSTORE date+".c"))
   write_file(OBSTORE date+".c","inherit \""+QOBJECT+"\";");
   SAVE();
}


void setup_quests()
{
    int x;
    x = 10 + (random(MAXSIZE)/2);
    while(x--)
    {
        if(random(2)) newMon();
        else newRoom();
        continue;
    }
    return;
}

void test_quests(){
   string where,name;
   string *dirs, *rooms, dir, room;
   int exp, base;
   int num;

   if (sizeof(keys(__Quests)) >= MAXSIZE) return;
   if(random(5)) return;

// was random(6)<3 but puts too many on mobs in Muileann for this group *Styx* 6/05
   if(random(8)<3) {
      newRoom();
	newMon();
   } else {
      newRoom();
   }
}

void isMon(object ob){
   string date, name, file;
   string thing, hold1, hold2;
   object obj;

   if(!objectp(ob)) return;

   file = base_name(ob)+".c";

   if(member_array(file, keys(__Monsters)) == -1) return;
   if(sizeof(__Monsters[file]) < 3) __Monsters[file] += ({0});
   if(__Monsters[file][2]) return;
   name = __Monsters[file][1];
   date = __Monsters[file][0];

   date = date + ".c";
   if(present(name,ob)) return;

   if(!file_exists(OBSTORE date))
      write_file(OBSTORE date,"inherit \""+QOBJECT+"\";");
   obj = find_object(OBSTORE date);
   if(!clonep(obj)){
      obj = new(OBSTORE date);
   }
   else return;
   sscanf(name,"%s %s %s",hold1, thing, hold2);
   obj->set_name(thing);
   obj->set_short(name);
   obj->set_obvious_short(thing);
   obj->set_long(name);
   obj->add_id(name);
   obj->add_id(thing);
   obj->add_id(date);
   obj->move(ob);
}

void isRoom(object ob){
   string date, name, file;
   string thing, hold1, hold2;
   object obj;

   if(!objectp(ob)) return;

   file = base_name(ob)+".c";

   if(member_array(file, keys(__Rooms)) == -1) return;
   if(sizeof(__Rooms[file]) < 3) __Rooms[file] += ({0});
   if(__Rooms[file][2]) return;
   name = __Rooms[file][1];
   date = __Rooms[file][0];

   date = date + ".c";
   if(present(name,ob)) return;

   if(!file_exists(OBSTORE date))
      write_file(OBSTORE date,"inherit \""+QOBJECT+"\";");
   obj = find_object(OBSTORE date);
   if(!clonep(obj)){
      obj = new(OBSTORE date);
   }
   else return;
   sscanf(name,"%s %s %s",hold1, thing, hold2);
   obj->set_name(thing);
   obj->set_short(name);
   obj->set_obvious_short(thing);
   obj->set_long(name);
   obj->add_id(name);
   obj->add_id(thing);
   obj->add_id(date);
   obj->move(ob);
}

mapping queryQuests(){
   return __Quests;
}

mapping queryMonsters(){
   return __Monsters;
}

mapping queryRooms(){
   return __Rooms;
}

void changeShort(string item, string newShort){
   if(__Quests[item])
      __Quests[item][3] = newShort;
   SAVE();
}

void gotten(string name){
   if(__Quests[name]){
      if(__Quests[name][0] == "monster") {
	 __Monsters[__Quests[name][1]][2]=1;
      }else{
	 __Rooms[__Quests[name][1]][2]=1;
      }
   }
   SAVE();
}

void resetItem(string name){
   if (!__Quests[name]) return;
   if(__Quests[name][0] == "room"){
        __Quests[name][3] = __Quests[name][1]->query_short();
	__Rooms[__Quests[name][1]][2] = 0;
   } else {
      if(__Quests[name][1]->query_invis()){
         __Quests[name][1]->set_invis();
         __Quests[name][3] = __Quests[name][1]->query_short();
        __Quests[name][1]->set_invis();
      } else {
	 __Quests[name][3] = __Quests[name][1]->query_short();
      }
      __Monsters[__Quests[name][1]][2] = 0;
   }
   SAVE();
}

int claimExp(string name, object player, int level){
   mapping used;
   string file,date;
   int exp, level2;
   if(member_array(name, keys(__Quests)) == -1) return 0;

   file = __Quests[name][1];
   exp = __Quests[name][2];

   if(__Quests[name][0] == "room"){
      date = __Rooms[file][0];
      map_delete(__Rooms,file);
   } else {
      date = __Monsters[file][0];
      map_delete(__Monsters,file);
   }
   map_delete(__Quests,name);
   rm(OBSTORE date+".c");
   tell_object(player,"%^BOLD%^%^BLUE%^You have claimed "+name+"!");
   seteuid(UID_LOG);
  log_file("player/rquests",capitalize(player->query_name())+"("+player->query_highest_level()+") retrieved the "+name+" ["+file+"].\n");
   seteuid(getuid());
   level2 = player->query_highest_level();
   if(level2 < level)
      exp = (((100 * level2)/level)*exp)/100;
// adding too much to spam to player file *Styx* 6/17/06
//   player->set_mini_quest("Found "+name,1,"Found "+name);
   if(!player->query("miniquest_exp")) {
	player->set("miniquest_exp", exp);
   } else {
	player->set("miniquest_exp", (exp + player->query("miniquest_exp")) );
   }
   player->add_exp(exp);
   test_quests();
   SAVE();
   return 1;
}

int clean_up(){
   return 1;
}

int clear_quests()
{
    string name;
    seteuid(UID_DAEMONSAVE);
    restore_object(SAVE_QUESTS);

    foreach(name in keys(__Quests))
    {
        removeQuest(name);
    }

    SAVE();

    test_quests();
}

void removeQuest(string name){
   mapping used;
 string file,date;
 int reDate;
 int exp;
 if(member_array(name, keys(__Quests)) == -1) return 0;
    if(!pointerp(__Quests[name])){
    map_delete(__Quests,name);
        return;
  }
 file = __Quests[name][1];
 exp = __Quests[name][2];
 reDate = __Quests[name][4];
 if(__Quests[name][0] == "room"){
   if( __Rooms[file]) {
    date = __Rooms[file][0];
    map_delete(__Rooms,file);
   }
 } else {
     if( __Monsters[file]) {
    date = __Monsters[file][0];
    map_delete(__Monsters,file);
   }
 }
 map_delete(__Quests,name);
 map_delete(__Removal, reDate);
 rm(OBSTORE date+".c");
 SAVE();
}

void heart_beat(){
   int *times, i,j;

   times = keys(__Removal);
   j = sizeof(times);
   for(i=0;i<j;i++){
     if(times[i] <= time()) {
       removeQuest(__Removal[times[i]]);
       if(member_array(times[i], keys(__Removal)) != -1) {
         map_delete(__Removal, times[i]);
       }
     }
   }
   if(!random(5))
   test_quests();
}
