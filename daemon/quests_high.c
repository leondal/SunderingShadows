#include <std.h>
#include <security.h>

inherit DAEMON;

/**
 * @file
 * @brief endgame collector items
 */

#define COLORS ({"%^RED%^red", "%^BLUE%^blue","%^CYAN%^cyan","%^GREEN%^green","%^MAGENTA%^magenta","%^YELLOW%^yellow","white","%^ORANGE%^orange","%^BOLD%^%^BLACK%^black"})
#define OBJECTS ({"chalice","parchment","tunic","boots","cup","bowl","knife","scroll","tablet","hat","tome","rod","statue","figurine","amulet","talisman","slippers","flask","candle","mirror","rug","brooch","egg","scarf", "sphere","cube","stone","crown","amulet","skull","pillar","doll","jar","ball","symbol","gem","halo"})

#define DESCRIPTS ({"brilliance","fortune","doom","power","evil","good","neutrality","the sun","the earth","the moon","the land","the sky","force","darkness","light","control","destiny","fortitude","cowardice","death","health","life","shielding","the universe","horror","beauty","comeliness","humility","pride","truth","lies","weakness","strength","nature","terror","fear","courage","wonder", "the cosmos","kittens","greyhounds","love"})

#define SAVE_QUESTS "/daemon/save/quests_high"

#define MED_H1 ({"/d/attaya", "/d/islands/tonerra/path/", "/d/islands/tonerra/mountain/", "/d/dagger/marsh/swamp/rooms/m", "/d/dagger/arctic/rooms/lake/", "/d/dagger/arctic/rooms/cave/", })

#define MED_H2 ({"/d/attaya", "/d/islands/common/aramanth/room", "/d/islands/argentrock/rooms/",  "/d/dagger/marsh/swamp/rooms/f", "/d/dagger/arctic/rooms/cave/","/d/islands/elf/ice/"})

#define HIGH ({"/d/islands/tonerra/monastary/m", "/d/attaya/base/", "/d/dagger/ogres/rooms/", "/d/deku/hhouse/rooms/","/d/dagger/marsh/tower/rooms/", "/d/antioch/ruins/portal/", "/d/laerad/cavern2/","/d/island/elf/shore/","/d/islands/dallyh/marsh/rooms/" })


#define UMM ({"/d/attaya/tower/", "/d/islands/tonerra/lava/","/d/islands/common/eldebaro/newrooms/tomb*","/d/islands/common/aramanth/d"})

#define AREAS      ({MED_H1, MED_H1, MED_H2, MED_H2, HIGH, HIGH, UMM})
#define AREA_VALUE ({150000, 300000, 450000, 550000, 650000, 760000, 850000})

#define MAXSIZE 25
#define QOBJECT "/d/common/obj/misc/qobject.c"
#define OBSTORE "/d/save/quests/"+

#define ANTIOCH "/d/antioch/"+
#define LAERAD "/d/laerad/"+
#define ATTAYA "/d/attaya/"+
#define DROW "/d/dagger/drow/"+
#define OGRE "/d/dagger/ogres/"+
#define D_MARSH "/d/dagger/marsh/"+
#define ISLANDS "/d/islands/"+
#define THARIS "/d/tharis/"+
#define AZHA "/d/azha/"+
#define DERRO "/d/dagger/derro/"+
#define SENUND "/d/attaya/senund/"+
#define DEKU "/d/deku/hhouse/mon/"+
#define ICE "/d/islands/elf/mon/"+


#define MONSTERS ([\
                        ANTIOCH "ruins/mons/demon.c" : 556000 ,\
                        ATTAYA "mon/bishimon.c" : 900000 ,\
                        ATTAYA "mon/ashtar.c" : 900000 ,\
                        ATTAYA "mon/callista.c":1000000 ,\
                        ATTAYA "mon/intruder.c" : 3000000 ,\
                        ATTAYA "mon/phaeton.c" : 700000 ,\
                        ATTAYA "mon/judatac.c" : 700000 ,\
                        ATTAYA "mon/volkerps.c" : 700000 ,\
                        ATTAYA "mon/magus.c" : 700000 ,\
                        ATTAYA "mon/io.c" : 700000 ,\
                        ATTAYA "mon/hunter.c" : 1000000 ,\
                        ATTAYA "mon/roper.c" : 1000000 ,\
                        DERRO "mon/elemental.c" : 300000 ,\
                        ISLANDS "argentrock/mon/watcher.c" : 480000 ,\
                        ISLANDS "argentrock/mon/batlin.c" : 4760000 ,\
                        ISLANDS "argentrock/mon/jarkunish.c" : 1500000 ,\
                        ISLANDS "argentrock/mon/kronibus.c" : 1560000 ,\
                        ISLANDS "argentrock/mon/fernibus.c" : 1560000 ,\
                        ISLANDS "common/mon/cruisertetron.c" : 5000000 ,\
                        "/d/antioch/wild/mount/muln/mon/muln.c" : 1800000 ,\
                        ISLANDS "tonerra/mon/edragon.c" : 1800000 ,\
                        ISLANDS "tonerra/mon/mmonk.c" : 456000 ,\
                        ISLANDS "tonerra/mon/tombt.c" : 1200000 ,\
                        ISLANDS "tonerra/mon/ibrandul.c" : 4800000 ,\
                        ISLANDS "tonerra/mon/nativek.c" : 1100000 ,\
                        ISLANDS "tonerra/mon/nativewd.c" : 292000 ,\
                        ISLANDS "dinosaur/mon/bmong.c" : 292000 ,\
                        LAERAD "mon/dragon.c" : 1120000 ,\
                        D_MARSH "tower/mon/dragon.c" : 2176000 ,\
                        D_MARSH "tower/mon/knight.c" : 1200000 ,\
                        D_MARSH "tower/mon/vecna.c" : 6000000 ,\
                        D_MARSH "tower/mon/angel.c" : 1200000 ,\
                        D_MARSH "tower/mon/grimmy.c" : 2000000 ,\
                        D_MARSH "tower/mon/nico.c" : 2000000 ,\
                        D_MARSH "tower/mon/render.c" : 4400000 ,\
                        OGRE "mobs/ahstuz.c" : 680000 ,\
                        SENUND "mon/elseroad.c" : 632000 ,\
                        SENUND "mon/gambrill.c" : 336000 ,\
                        SENUND "mon/geilfuss.c" : 500000 ,\
                        SENUND "mon/priest.c" : 360000 ,\
                        DEKU "zhour_husk.c" : 640000 ,\
                        DEKU "arag_dyne.c" : 640000 ,\
                        DEKU "assassin.c" : 600000 ,\
                        DEKU "narameon.c" : 600000 ,\
                        DEKU "bandit_l.c" : 640000 ,\
                        DEKU "black_beast.c" : 360000 ,\
                        DEKU "aurus_devar_bones.c" : 2000000 ,\
                        ICE "squid.c" : 1000000 ,\
                        ICE "capn.c" : 1000000 ,\
                        ICE "daelas.c" : 1000000 ,\
                        "/d/islands/common/eldebaro/mon/arsheeva_wyndar.c" : 5500000,\
                        ])

mapping __Quests, __Rooms, __Monsters;
mapping __Removal;

void test_quests();
void createDumby(object ob);


string query_name() { return "High random quests daemon."; }
string query_short() { return "High random quests daemon"; }


protected void SAVE()
{
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_QUESTS);
    seteuid(getuid());
}

void create()
{
    ::create();

    __Quests = ([]);
    __Monsters = ([]);
    __Rooms = ([]);
    __Removal = ([]);

    seteuid(UID_DAEMONSAVE);
    restore_object(SAVE_QUESTS);

    if(!__Quests)   { __Quests = ([]); }
    if(!__Monsters) { __Monsters = ([]); }
    if(!__Rooms)    { __Rooms = ([]); }
    if(!__Removal)  { __Removal == ([]); }

    SAVE();

    test_quests();
    set_heart_beat(30);
}

string makeObject()
{
    int i,j,k;
    string hold;

    i = random(sizeof(COLORS));
    j = random(sizeof(OBJECTS));
    k = random(sizeof(DESCRIPTS));

    hold = COLORS[i]+" "+OBJECTS[j]+" of "+DESCRIPTS[k];
    return hold;
}


void newMon()
{
    string name, file, short;
    int exp, date, reDate, flag;


    name = makeObject();
    flag = 0;
    while (member_array(name, keys(__Quests)) != -1)
    {
        name = makeObject();
        flag++;
        if(flag > 20) return; // failsafe
    }
    file = keys(MONSTERS)[random(sizeof(keys(MONSTERS)))];
    flag = 0;
    while (member_array(file, keys(__Monsters)) != -1)
    {
        file = keys(MONSTERS)[random(sizeof(keys(MONSTERS)))];
        flag++;
        if(flag > 20) return; // failsafe
    }
    date = time();

    // lowering the adder to half to narrow range for better reasonableness *Styx* 6/12/05
    exp = MONSTERS[file]+(random(MONSTERS[file])/2);
    exp = exp +random(exp);// (2 + random(2));
    __Monsters[file] = ({date,name});

    reDate = date+86400+random(86400*1);

    while(__Removal[reDate])
    {
        reDate = date+86400+random(86400*5);
    }

    if(file->query_invis())
    {
        file->set_invis();
        short = file->query_short();
        file->set_invis();
    }
    else
    {
        short = file->query_short();
    }

    __Quests[name] = ({"monster", file, exp, short, reDate});
    __Removal[reDate] = name;
    __Monsters[file] = ({date, name, 0});

    if(!file_exists(OBSTORE date+".c"))
    {
        write_file(OBSTORE date+".c","inherit \""+QOBJECT+"\";");
    }
    SAVE();
}


string *NotValidDir()
{
    int x;
    string *tmp, *tmp2, *tmp3;
    tmp = ({});
    tmp2 = MED_H1 + MED_H2 + HIGH + UMM;
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


void newRoom()
{
    string name, file, dir, *files;
    int i,exp, date, reDate, flag;

    i = random(sizeof(AREAS));
    dir = AREAS[i][random(sizeof(AREAS[i]))];

    files = get_dir(dir+"*.c");
   if(sizeof(files)==1 && member_array(files[0], keys(__Rooms)) != -1)
       return;
    exp = AREA_VALUE[i] + (random(AREA_VALUE[i])/2);

    name = makeObject();
    flag = 0;
    while (member_array(name, keys(__Quests)) != -1)
    {
        name = makeObject();
        flag++;
        if(flag > 20) return; // failsafe
    }

    if(!sizeof(files))
    {
        seteuid(UID_LOG);
        seteuid(getuid());
        return;
    }

    while(dir[strlen(dir)-1] != '/')
    {
        dir = dir[0..strlen(dir)-2];
    }

    file =  files[random(sizeof(files))];
    flag = 0;

    while (member_array(file, keys(__Rooms)) != -1 ||
           member_array(file, values(map(__Quests,(:$2[1]:)))) != -1 ||
           undefinedp((dir+file)->query_short()))
    {
        file =  files[random(sizeof(files))];
        flag++;
        if(flag > 20) return; // failsafe
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
    {
        write_file(OBSTORE date+".c","inherit \""+QOBJECT+"\";");
    }

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


void test_quests()
{
    string where,name;
    string *dirs, *rooms, dir, room;
    int exp, base;
    int num;

    if (sizeof(keys(__Quests)) >= MAXSIZE) return;

    if(random(5) < 3)
    {
        newRoom();
        newMon();
    }
    else
    {
        newRoom();
    }
}


void isMon(object ob)
{
    string date, name, file;
    string thing, hold1, hold2;
    object obj;

    if(!objectp(ob)) return;

    file = base_name(ob)+".c";

    if(member_array(file, keys(__Monsters)) == -1) { return; }

    if(sizeof(__Monsters[file]) < 3) { __Monsters[file] += ({0}); }

    if(__Monsters[file][2]) { return; }

    name = __Monsters[file][1];
    date = __Monsters[file][0];

    date = date + ".c";

    if(present(name,ob)) return;

    if(!file_exists(OBSTORE date))
    {
        write_file(OBSTORE date,"inherit \""+QOBJECT+"\";");
    }

    obj = find_object(OBSTORE date);

    if(!clonep(obj))
    {
        obj = new(OBSTORE date);
    }
    else { return; }

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


void isRoom(object ob)
{
    string date, name, file;
    string thing, hold1, hold2;
    object obj;

    if(!objectp(ob)) { return; }

    file = base_name(ob)+".c";

    if(member_array(file, keys(__Rooms)) == -1) { return; }

    if(sizeof(__Rooms[file]) < 3) { __Rooms[file] += ({0}); }

    if(__Rooms[file][2]) { return; }

    name = __Rooms[file][1];
    date = __Rooms[file][0];

    date = date + ".c";
    if(present(name,ob)) { return; }

    if(!file_exists(OBSTORE date))
    {
        write_file(OBSTORE date,"inherit \""+QOBJECT+"\";");
    }

    obj = find_object(OBSTORE date);

    if(!clonep(obj))
    {
        obj = new(OBSTORE date);
    }
    else { return; }

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


createDumby(object ob)
{
    string thing;
    object obj;

    if(random(500))
    {
        return;
    }

    thing = OBJECTS[random(sizeof(OBJECTS))];
    obj = new (QOBJECT);
    obj->set_short(thing);
    obj->set_obvious_short(thing);
    obj->set_long("This is "+article(thing)+" "+thing+".");
    obj->add_id(thing);
    obj->move(ob);
    obj->set_value(random(100));
}


mapping queryQuests() { return __Quests; }

mapping queryMonsters() { return __Monsters; }

mapping queryRooms() { return __Rooms; }


void changeShort(string item, string newShort)
{
    if(__Quests[item])
    {
        __Quests[item][3] = newShort;
    }
    SAVE();
}


void gotten(string name)
{
    if(__Quests[name])
    {
        if(__Quests[name][0] == "monster")
        {
            __Monsters[__Quests[name][1]][2]=1;
        }
        else
        {
            __Rooms[__Quests[name][1]][2]=1;
        }
    }
    SAVE();
}


void resetItem(string name)
{
    if (!__Quests[name]) return;

    if(__Quests[name][0] == "room")
    {
        __Quests[name][3] = __Quests[name][1]->query_short();
        __Rooms[__Quests[name][1]][2] = 0;
    }
    else
    {
        if(__Quests[name][1]->query_invis())
        {
            __Quests[name][1]->set_invis();
            __Quests[name][3] = __Quests[name][1]->query_short();
            __Quests[name][1]->set_invis();
        }
        else
        {
            __Quests[name][3] = __Quests[name][1]->query_short();
        }
        __Monsters[__Quests[name][1]][2] = 0;
    }
    SAVE();
}


int claimExp(string name, object player, int level)
{
    mapping used;
    string file,date;
    int exp, level2;

    //write("name = "+name);

    if(member_array(name, keys(__Quests)) == -1) { return 0; }
    if(!pointerp(__Quests[name])) { return 0; }

    file = __Quests[name][1];
    exp = __Quests[name][2];

    if(__Quests[name][0] == "room")
    {
        date = __Rooms[file][0];
        map_delete(__Rooms,file);
    }
    else
    {
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

    if(!player->query("miniquest_exp"))
    {
        player->set("miniquest_exp", exp);
    }
    else
    {
        player->set("miniquest_exp", (exp + player->query("miniquest_exp")) );
    }

    player->add_exp(exp);
    test_quests();
    SAVE();
    return 1;
}


int clean_up() { return 1; }

int clear_quests()
{
    string name;

    foreach(name in keys(__Quests))
    {
        removeQuest(name);
    }

    seteuid(UID_DAEMONSAVE);
    SAVE();

    test_quests();
}

void removeQuest(string name)
{
    mapping used;
    string file,date;
    int reDate;
    int exp;

    if(member_array(name, keys(__Quests)) == -1) { return 0; }

    if(!pointerp(__Quests[name]))
    {
        map_delete(__Quests,name);
        return;
    }

    file = __Quests[name][1];
    exp = __Quests[name][2];
    reDate = __Quests[name][4];

    if(__Quests[name][0] == "room")
    {
        if( __Rooms[file])
        {
            date = __Rooms[file][0];
            map_delete(__Rooms,file);
        }
    }
    else
    {
        if( __Monsters[file])
        {
            date = __Monsters[file][0];
            map_delete(__Monsters,file);
        }
    }

    map_delete(__Quests,name);
    map_delete(__Removal, reDate);
    rm(OBSTORE date+".c");
    SAVE();
}


void heart_beat()
{
    int *times, i,j;

    times = keys(__Removal);
    j = sizeof(times);
    for(i=0;i<j;i++)
    {
        if(times[i] <= time())
        {
            removeQuest(__Removal[times[i]]);
            if(member_array(times[i], keys(__Removal)) != -1)
            {
                map_delete(__Removal, times[i]);
            }
        }
    }
    if(!random(3))
    test_quests();
}
