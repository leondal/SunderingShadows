//caravan.c

#include <std.h>

inherit WEAPONLESS;

mapping guards;
string *path;
mapping contents;
object *playerGuards;
object *guardObjs;
mapping bandits;
int speed;
int speedCount;
string startingPath;
string deathObject = "/std/obj/wagon";

int chance;


int position = 0;


void create() {
    ::create();
/*
    set_num_attacks(0);
    set_attack_limbs(({"wagon"}));
    set_heart_beat(1);
    heart_beat_on = 20;
    guardObjs = ({});
    call_out("setup",2);
    add_limb("wagon","wagon",0,0,0);
    set_hp(1);
    speed = 10;
*/
    TO->remove();
    return;
}

void setDeathObject(string obj) {
    deathObject = obj;
}

string getDeathObject() {
    return deathObject;
}


int test_heart() {
    return 1;
}

/**
 * The room path that this caravan should start in
 */
void setStartingPath(string path) {
    startingPath = path;
}

string getStartingPath() {
    return startingPath;
}


void setGuards(mapping guardsMap) {

    guards = guardsMap;
}

mapping getGuards() {
    return guards;
}

void setBandits(mapping banditsMap) {
    bandits = banditsMap;
}

mapping getBandits() {
    return bandits;
}

void setBanditChance(int xxx) {
    chance = xxx;
}


void setPath(string * caravanPath) {
    path = caravanPath;
}

string *getPath() {
    return path;
}

void setContents(mapping caravanContents) {
    contents = caravanContents;
}

mapping getContents() {
    return contents;
}


void addPlayerGuard(object ob) {
    if(!objectp(ob)) {
        return;
    }
    if(!playerGuards) {
        playerGuards = ({});
    }
    playerGuards += ({ob});
}

object *getPlayerGuards() {
    return playerGuards;
}

object *getAllGuards() {
  /*  int i,j;
    object *stuff=({});
    object *stuff2;

    log_file("debug.log","/std/caravan.c line 123, previous object was: "+identify(PO));
    stuff += playerGuards;
    stuff += guardObjs;
    stuff2 = stuff;
    for(i = 0;i<sizeof(stuff);i++) {

        if(!objectp(stuff[i])) {
            stuff2 -= ({stuff[i]});
        }
    }
    return stuff2;*/ return ({});
}

void setSpeed(int xx) {
    speed = xx;
    //set_heart_beat(speed);
    heart_beat_on = speed;
}

int getSpeed() {
    return speed;
}

int do_damage(string limb, int i) {
    if(sizeof(getAllGuards()) < 1) {
        return ::do_damage(limb,i);
    }

    return 0;

}


void die(object ob) {
    int tmp_size, keySize,i,j;
    string *currs, *keyS;
    object obj;
    object wagon_ob;

    wagon_ob = new(getDeathObject());
    keyS = keys(contents);
    keySize = sizeof(keyS);
    if(keySize) {
        for(i=0; i<keySize; i++) {
            for(j = 0;j<contents[keyS[i]];j++) {
                obj = new (keyS[i]);
                obj->move(wagon_ob);
            }

        }
    }
    tmp_size=sizeof(currs=query_currencies());
    if(tmp_size) {
        obj = new("/std/obj/coins");
        for(i=0; i<tmp_size; i++) {
            obj->add_money(currs[i], query_money(currs[i]));
            add_money(currs[i], -query_money(currs[i]));
        }
        obj->move(wagon_ob);
    }
    wagon_ob->move(ETO);
    TO->remove();


}

void checkGuards() {
    int i,j;
    object *attkrs;
    object * guards = getAllGuards();

    for(i=0;i<sizeof(guards);i++) {
        if(!objectp(guards[i])) continue;
        attkrs = guards[i]->query_attackers();
        if(sizeof(attkrs) >0) {
            for(j=0;j<sizeof(attkrs);j++) {
                if(!objectp(attkrs[j])) continue;
                if(member_array(attkrs[j],TO->query_attackers()) == -1)
                    TO->add_attacker(attkrs[j]);
            }
        }
    }
}

void heart_beat() {
    string direction;
    int j,i;
    string * key;
    object ob;
    ::heart_beat();
    speedCount++;

    checkGuards();
    //tell_room(ETO,"speed = "+speed);
    if(speedCount < speed) {
        return;
    }
    speedCount = 0;
    position++;
    direction = path[position];
    switch(direction) {
    case "d":
        direction = "down";
        break;
    case "u":
        direction = "up";
        break;
    case "nw":
        direction = "northwest";
        break;
    case "ne":
        direction = "northeast";
        break;
    case "se":
        direction = "southeast";
        break;
    case "sw":
        direction = "southwest";
        break;
    case "w":
        direction = "west";
        break;
    case "e":
        direction = "east";
        break;
    case "s":
        direction = "south";
        break;
    case "n":
        direction = "north";
        break;
    }
    force_me(direction);
    if(chance > roll_dice(1,100)) {
        key = keys(bandits);
        for(i=0;i<sizeof(key);i++) {
            for(j=bandits[key[i]];j>0;j--) {
                ob = new(key[i]);
                ob->move(ETO);
                ob->force_me("kill caravan");
                add_follower(ob);

            }
        }
    }

}

void setup() {
    string key;
    object ob;
    int i,j;
    if(!guards || !objectp(environment(TO))) {
        call_out("setup",2);
        return;
    }
    key = keys(guards);
    for(i=0;i<sizeof(key);i++) {
        for(j=guards[key[i]];j>0;j--) {
            ob = new(key[i]);
            ob->move(ETO);
            guardObjs += ({ob});
            add_follower(ob);

        }
    }


}

object * query_protectors() {
    return getAllGuards();
}

object * doProtection(object obj) {
    if(!sizeof(getAllGuards())) {
        return ({TO});
    }
    //tell_room(ETO,"calling protection");
    return getAllGuards();
}




