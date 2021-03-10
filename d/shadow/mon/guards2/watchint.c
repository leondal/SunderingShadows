//
#include <std.h>


#define GUARD_D "/d/shadow/mon/guards/guard_d"
#define BAD_RACES ({"drow","half-drow","goblin","hobgoblin","kobold","ogre","half-ogre","orc","half-orc","gnoll","bugbear","troll","ratkin"})

inherit NPC;

int do_laws();

void interactions();

string randomRaceMessage(object x);

int do_races();

int isWatch() {
    return 1;
}

void create(){
    ::create();
    set_save_monster(1);
    enable_commands();
    set_property("knock unconscious",1);
}


int interaction;

void heart_beat(){
    object *watch, *other_attackers;
    int i, j;
    ::heart_beat();

//    if(!interaction) {
//        interaction = 1;
        interactions();
//        interaction = 0;
//    }

    if(objectp(TO) && objectp(ETO)) {
        watch = all_present("shadow law",ETO);
        for(i = 0;i<sizeof(watch);i++) {
            other_attackers = watch[i]->query_attackers();
            for ( j = 0;j<sizeof(other_attackers);j++){
                if (!objectp(other_attackers[j])) {
                    continue;
                }
                if (!other_attackers[j]->query_bound() && !other_attackers[j]->query_unconscious()) {
                    add_attacker(other_attackers[j]);
                }
            }
        }
    }

}

void interactions(){
    do_laws();
    do_races();

}

string getSaveFileName() {
    string fn;
    fn = npc::getSaveFileName();
    fn = fn + "_"+query_name();
    return fn;

}
do_laws(){

}

do_races(){
    int i;
    object *lives;
    if (!objectp(TO)) {
        return;
    }

    if (!objectp(ETO)) {
        return;
    }
    lives = all_living(ETO);
    for (i =0;i<sizeof(lives);i++) {
        if (!objectp(lives[i])) {
            continue;
        }
          if (!lives[i]->query_invis() && member_array((string)lives[i]->query_race(),BAD_RACES) != -1) {
             if (member_array(lives[i], query_attackers()) == -1 && !lives[i]->query_unconscious() && !lives[i]->query_bound()) {
                command("yell "+randomRaceMessage(lives[i]));
                command("rush "+lives[i]->query_name());
                kill_ob(lives[i],0);
            }
        }
    }


}




void hairColor(){
    switch(random(6)) {
        case 0:
            set("hair","blonde");
            break;
        case 1:
            set("hair","red");
            break;
        case 2:
            set("hair","auborn");
            break;
        case 3:
            set("hair","black");
            break;
        case 4:
            set("hair","gray");
            break;
        case 5:
            set("hair","white");
            break;
    }
}

void eyeColor(){
    switch(random(5)) {
        case 0:
            set("eye","blue");
            break;
        case 1:
            set("eye","gray");
            break;
        case 2:
            set("eye","green");
            break;
        case 3:
            set("eye","brown");
            break;
        case 4:
            set("eye","azure");
            break;
    }
}
void doHeight(){
    int feet, halves;
    int height = 63+random(20);
    feet = height/12;
    halves = "";
    if(height%12) {
        halves = (height%12<4)?"":((height%12<9)?" and a half":"");
        if(height%12>8) {
            height++;
        }
    }
    set("height",""+feet+halves);

}

void doWeight(){
    set("weight",((140+random(140))/10)*10);

}

void doGender(){
    set_gender(random(2)?"male":"female");

}

void setupName(){
    string name;
    name = GUARD_D->do_name();
    set_name(name);
    set_short(capitalize(name)+", "+article(query("hair"))+" "+query("hair")+" haired, "+query("eye")+" eyed "+query_gender()+" human");
    add_id(name);
    add_id(capitalize(name));
    add_id(lower_case(name));

}



void die(object ob){
    remove_save();
    ::die();

}

int kill_ob(object ob, int i){
    int hold;
    hold = ::kill_ob(ob,i);
    if(hold) {
        GUARD_D->blow_horn(TO);
        GUARD_D->call_watch(TO, ob);
    }
    return hold;

}

string randomRaceMessage(object x){
    string msg;
    string race = (string)x->query_race();
    switch (race) {
    case "drow":
        msg = "Arg, its a drow, sound the horn, stop him before he starts killing children.";
        break;
    case "half-drow":
        msg = "Stop the bastard half-drow, any drow blood is bad.";
        break;
    case "goblin":
        msg = "Stop that miserable little goblin, and look around for more.";
        break;
    case "hobgoblin":
        msg = "Careful folks, its a hobgoblin, I'll take care of him.";
        break;
    case "kobold":
        msg = "Dog faced rat, stop you kobold.";
        break;
    case "ogre":
        msg = "Gods help us, its an ogre, how did he get past the gate?";
        break;
    case "gnoll":
        msg = "Its a gnoll fellas, take 'em";
        break;
    case "half-ogre":
        msg = "Half-ogres are just smaller ogres, can't allow them in here.";
        break;
    case "half-orc":
        msg = "Its not human fellas, get that half-orc.";
        break;
    case "bugbear":
        msg = "Take em low, boys. He's gonna be mean, don't let that bugbear take you alive.";
        break;
    case "orc":
        msg = "Don't let the orcs escape, You know he's spying for an inviasion.";
        break;
    default:
        msg = "Stop you heinous "+race+".";
    }

    return msg;

}
