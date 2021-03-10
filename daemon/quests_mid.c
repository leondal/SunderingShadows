#include <std.h>
#include <security.h>

/**
 * @file
 * @brief Midgame collector items
 */


inherit DAEMON;

#define COLORS ({"%^RED%^red", "%^BLUE%^blue","%^CYAN%^cyan", "%^GREEN%^green", "%^MAGENTA%^magenta", "%^YELLOW%^yellow","white","%^ORANGE%^orange","%^BOLD%^%^BLACK%^black"})

#define OBJECTS ({"chalice","parchment","tunic","boots","cup","bowl", "knife", "scroll", "tablet","hat","tome","rod","statue","figurine","amulet", "talisman", "slippers", "flask","candle","mirror","rug","brooch","egg","scarf", "sphere", "cube", "stone", "crown", "amulet","paw","feather","tooth","tail"})

#define DESCRIPTS ({"brilliance","fortune","doom","power","evil","good", "neutrality", "the sun","the earth","the moon","the land","the sky", "force", "darkness", "light", "control", "destiny", "fortitude", "cowardice","death","health", "life", "shielding", "the universe", "horror", "beauty", "comeliness","humility","pride", "truth", "lies", "weakness", "strength", "nature", "terror", "fear", "courage", "wonder", "kittens","hounds","whiskers","bunnies"})

#define SAVE_QUESTS "/daemon/save/quests_mid"

#define LMID1 ({"/d/deku/plains/", "/d/deku/fortress/", "/d/deku/keep/rooms/t", "/d/deku/plains/", "/d/deku/forest/", "/d/islands/pirates/cove/path", })

#define LMID2 ({"/d/tharis/newtharis/sewers", "/d/barriermnts/ruins/room/", "/d/deku/sanctuary/sewer/", "/d/azha/theater/rooms/", "/d/deku/forest/fire_tunnel/rooms/"})

#define MED ({"/d/deku/keep/rooms/blacktonguelair", "/d/laerad/parnelli/asgard/sewer/rooms/", "/d/islands/pirates/cove/boat", "/d/underdark/mines/room/", "/d/islands/pirates/caves/", "/d/antioch/valley/rooms/e", "/d/antioch/valley/rooms/dt","/d/islands/coralsea/rooms/"})

#define HMID1 ({"/d/laerad/plains/", "/d/laerad/swamp/", "/d/laerad/parnelli/forest/", "/d/laerad/wasteland/", "/d/tharis/forest/", "/d/deku/sanctuary/tower/", "/d/deku/keep/rooms/dungeon"})

#define HMID2 ({"/d/laerad/parnelli/systyquah/", "/d/antioch/valley/rooms/v", "/d/antioch/valley/rooms/g", "/d/islands/dallyh/forest/rooms/", "/d/tharis/barrow/rooms/mound", "/d/barriermnts/bpeak/rooms/",\
"/d/barriermnts/lothwaite/rooms/bt", "/d/dagger/derro/rooms/c", "/d/deku/mausoleum/rooms/","/d/shadow/room/deep_echos/","/d/antioch/valley/rooms/v","/d/laerad/cavern1/","/d/antioch/greaterantioch/rooms/foothills/foothills11/"})

#define AREAS ({ LMID1, LMID2, MED, HMID1, HMID2})
#define AREA_VALUE ({60000, 80000, 100000, 120000, 140000})

#define MAXSIZE 30
#define QOBJECT "/d/common/obj/misc/qobject.c"
#define OBSTORE "/d/save/quests/"+

#define ANTIOCH "/d/antioch/"+
#define LAERAD "/d/laerad/"+
#define DEKU "/d/deku/"+
#define DROW "/d/dagger/drow/"+
#define D_MARSH "/d/dagger/marsh/"+
#define ISLANDS "/d/islands/"+
#define UNDERDARK "/d/underdark/"+
#define THARIS "/d/tharis/"+
#define AZHA "/d/azha/"+
#define KOENIG "/d/koenig/town/"+
#define SHADOW "/d/shadow/"+
#define DERRO "/d/dagger/derro/"+
#define BARRIER "/d/barriermnts/ruins/mon/"+
#define SANCT "/d/deku/sanctuary/mon/"+

#define MONSTERS ([\
                        ANTIOCH "valley/mons/bear.c": 75000,\
                        ANTIOCH "valley/mons/creeper.c": 75000,\
                        ANTIOCH "greaterantioch/mon/faris.c": 90000,\
                        ANTIOCH "greaterantioch/mon/gnollchieftain.c": 80000,\
                        DEKU "monster/jarrow.c":75000,\
                        DEKU "monster/lord.c":75000,\
                        DEKU "monster/serpent.c":78000,\
                        DEKU "fortress/monster/nightmare.c":78000,\
                        DEKU "keep/monster/lord.c":80000,\
                        DEKU "keep/monster/ingmar.c":75000,\
                        DEKU "keep/monster/siere.c":88000,\
                        DEKU "keep/monster/lordblacktongue.c":125000,\
                        DEKU "keep/monster/shaltul.c":78000,\
                        DEKU "keep/monster/telair.c":78000,\
                        DEKU "monster/skel-king.c":86000,\
                        DEKU "monster/hill.c":75000,\
                        SANCT "balkour.c":97500,\
                        SANCT "auica.c":95000,\
                        SANCT "everardus.c":80000,\
                        AZHA "mon/alradin.c":97500,\
                        AZHA "mon/alsura.c":94000,\
                        AZHA "theater/mons/mashiva.c":84000,\
                        AZHA "theater/mons/marion_bard.c":86000,\
                        AZHA "theater/mons/marion_ranger.c":86000,\
                        AZHA "theater/mons/ivashka_harpy.c":92000,\
                        DERRO "mon/cook.c": 12000,\
                        DERRO "mon/fireking.c": 125000,\
                        "/d/dagger/road/mon/thorby.c": 125000,\
                        "/d/darkwood/yntala/mon/lepking.c": 86000,\
                        "/d/islands/coralsea/mon/coral_captain.c": 90000,\
                        ISLANDS "pirates/mon/firstmate.c":90000,\
                        ISLANDS "pirates/mon/piratecaptain.c":95000,\
                        ISLANDS "pirates/mon/shadowmonster.c":105000,\
                        ISLANDS "pirates/mon/cedwin.c":105000,\
                        THARIS "barrow/mon/knight.c":95000,\
                        THARIS "barrow/mon/krykoth.c":95000,\
                        THARIS "monsters/forestd.c":200000,\
                        THARIS "monsters/steeldragon.c":200000,\
                        THARIS "monsters/black_mage.c":90000,\
                        THARIS "monsters/white_mage.c":90000,\
                        LAERAD "mon/skuz.c":102000,\
                        LAERAD "mon/anti.c":102000,\
                        LAERAD "mon/paladin.c":104000,\
                        LAERAD "mon/lich.c":154000,\
                        LAERAD "parnelli/asgard/sewer/mons/lking.c":105000,\
                        BARRIER "mage.c":90000,\
                        BARRIER "wyvern.c":90000,\
                        D_MARSH "swamp/mon/harv.c":94500,\
                        UNDERDARK "mines/mon/kobsorc.c":94500,\
                        UNDERDARK "mines/mon/gnowarden.c":94500,\
                        ])


mapping __Quests, __Rooms, __Monsters;
mapping __Removal;

void test_quests();

string query_name() { return "Mid random quests daemon"; }
string query_short() { return "Mid random quests daemon"; }

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
/*
int query_generic_list() {
   return GEN_LIST;
}
*/
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
   file = keys(MONSTERS)[random(sizeof(keys(MONSTERS)))];

   while (member_array(file, keys(__Monsters)) != -1) {
      file = keys(MONSTERS)[random(sizeof(keys(MONSTERS)))];
   }
   date = time();
// lowering the adder to half to narrow range for better reasonableness *Styx* 6/12/05
   exp = MONSTERS[file]+(random(MONSTERS[file])/2);
   exp = exp * (3 + random(2));
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
	tmp2 = LMID1 + LMID2 + MED + HMID1 + HMID2;
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
// changing this to check for size of the areas list rather than being hard coded *Styx* 7/13/05
//   i= random(7);
   i = random(sizeof(AREAS));
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
       flag++;
       file =  files[random(sizeof(files))];
       if(flag>20)
           return;
   }

   while(dir[strlen(dir)-1] != '/'){
      dir = dir[0..strlen(dir)-2];
   }
   file = dir+file;
   date = time();

   reDate = date+86400+random(86400*5);
   while(__Removal[reDate])
   {
     reDate = date+86400+random(86400*5);
     continue;
   }

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
   if(random(6)<3){
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
   float exp, level2;
   if(member_array(name, keys(__Quests)) == -1) return 0;

   file = __Quests[name][1];
   exp = __Quests[name][2];
     tell_object(find_player("saide"), "Exp = "+exp);
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
    tell_object(find_player("saide"), "Exp = "+exp);
// adding too much to spam to player file *Styx* 6/17/06
//   player->set_mini_quest("Found "+name,1,"Found "+name);
   if(!player->query("miniquest_exp")) {
	player->set("miniquest_exp", exp);
   } else {
	player->set("miniquest_exp", (exp + player->query("miniquest_exp")) );
   }
   if(find_player("saide"))
   {
       tell_object(find_player("saide"), "player = "+identify(player) + " should be gaining "+exp+" exp. Quest item level = "+level+" level2 = "+level2);
   }
   exp = to_int(exp);
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
