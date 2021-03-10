//jungle island inheritable
//jungle.c
//added a check so that the spears won't hit true-invis people. Nienne, 1/05
//updated to make sure there is a down exit to ankheg rooms - should not be trapped - Saide

//Updated chances of monsters spawning and how many spawn. -- Tlaloc -- 11/19

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

string what,ank_dir;
object room;

int flag;
void create(){
        ::create();
        set_terrain(JUNGLE);
        set_travel(FOOT_PATH);
    set_climate("tropical");
}

void reset()
{
    object *temp,ob;
    int i;
    string *str,dir;
    ::reset();
    if(!objectp(room))
    {
        if(query_property("ankeg_room"))
        {
            remove_property("ankeg_room");
            remove_exit("down");
        }
    }

    if(!pointerp(TO->query_exits()) || !sizeof(TO->query_exits()))
    {
        flag =1;
        return;
    }
    if(!present("bad boy") && !TO->query_traps() && !random(2))
    {


        str = (string *)TO->query_exits();
        str -= ({"down"});
        dir = str[random(sizeof(str))];

        switch (random(50))
            {

            case 0..5:
            if(objectp(room))
                break;
            set_trap_functions(({dir}),({"ankheg"}),({dir}));
            ank_dir = dir;
            add_item("ground","The ground to the "+dir+" seems weak.");
            what = "ankheg&"+dir;
            break;
            case 6..9:
            set_trap_functions(({dir}),({"tasloi"}),({dir}));
            add_item("trees","There seems to be something hidden in the trees toward the "+dir+".");
            what = "tasloi&"+dir;
            break;
            case 10..17:
            set_trap_functions(({dir}),({"native"}),({dir}));
            add_item("bushes","There seems to be something hidden in the bushes toward the "+dir+".");
            what = "native&"+dir;
            break;
            case 18..20:
            ob = new(MON+"rgargantua");
            ob->add_id("bad boy");
            ob->move(TO);
            break;
            case 21..25:
            ob = new(MON+"aurumvorax");
            ob->add_id("bad boy");
            ob->move(TO);
            break;
            default:
            temp = "/d/islands/tonerra/mon/tonerra_d"->make_party(TO);
            for(i=0;i<sizeof(temp);i++)
                temp[i]->add_id("bad boy");
        }
    }
}


void set_ankheg_room(object myroom)
{
    if(!objectp(myroom)) return;
    room = myroom;
}

int ankheg(){
        string verb;
        object ob;

        verb = query_verb();

        tell_room(TO,"As "+TPQCN+" wanders "+verb+" the ground below "+TP->query_objective()+"
shudders and opens.",TP);
        tell_object(TP,"As you walk "+verb+" the ground shudders and opens under you.");
        if(!objectp(room))
    {

        room = new(PATH+"ankheghouse");
//       room->add_exit(TO->query_exit(verb),"up"); - This is what it was.
//Changing to below to try to fix a bug.  Circe 6/14/07
        room->add_exit(TO->query_exit(ank_dir),"up");
        }
        TO->query_exit(ank_dir)->add_exit(file_name(room), "down");
        TO->query_exit(ank_dir)->set_property("ankeg_room", 1);
        TO->query_exit(ank_dir)->set_ankheg_room(room);
        TP->move_player(room);
        //toggle_trap(verb);
        return 1;
}


int tasloi(){
        string verb;
        object ob,*inven,*tmp;
        int i,j,k,l;

        verb = query_verb();
        if(TP->query_invis()) return 0;
        tell_room(TO,"As "+TPQCN+" wanders "+verb+" the trees above "+TP->query_objective()+" come
alive as a net is thrown down.",TP);
        tell_object(TP,"As you walk "+verb+" the trees above you seem to come alive and a net is
thrown down upon you.");
        inven = all_living(TO);
        inven -= ({TP});
        tmp = ({TP});
        j = sizeof(inven);
        for(i=0;i<j;i++){
                 if(!random(4))
                        tmp += ({inven[i]});
        }
        j = sizeof(tmp);
        for(i=0;i<j;i++){
                if(tmp[i]->query_stats("strength") > 14)
                        tmp[i]->set_paralyzed(20,"You are entangled in the net");
                else
                        tmp[i]->set_paralyzed(40,"You are entangled in the net.");
                tell_object(tmp[i],"You are caught in the net thrown by the tasloi");
        }
        j = roll_dice(5,6);
        for(i=0;i<j;i++){
                ob= new(MON+"tasloi");
                ob->add_id("bad boy");
                ob->move(TO);
                l = sizeof(tmp);
                for(k=0;k<l;k++){
                        ob->kill_ob(tmp[k],1);
                }
        }


        tell_room(TO,"An Army of tasloi drop from the trees and attack the captured.");

        toggle_trap(verb);
        return 1;
}

int is_immortal(object ob) {
   if(!ob->query_true_invis()) return 1;
   else return 0;
}

int native()
{
    string verb;
    object ob,*inven,*inven2,tmp;
    int i,j,k,l;

    verb = query_verb();
    if(TP->query_invis()) return 0;
    tell_room(TO,"As "+TPQCN+" wanders "+verb+" the bushes around "+TP->query_objective()+" come alive and spears fly through the air.",TP);
    tell_object(TP,"As you walk "+verb+" the bushes around you come alive and spears fly through the air!");
    inven2 = all_living(TO);
    inven = filter_array(inven2,"is_immortal",TO);
    l = sizeof(inven);
    ob= new(MON+"native");
    ob->add_id("bad boy");
    ob->move(TO);
    for(k=0;k<l;k++)
    {
        ob->kill_ob(inven[k],1);
    }
    ob= new(MON+"native");
    ob->add_id("bad boy");
    ob->move(TO);
    for(k=0;k<l;k++)
        ob->kill_ob(inven[k],1);
    ob= new(MON+"nativeS");
    ob->add_id("bad boy");
    ob->move(TO);
    for(k=0;k<l;k++)
        ob->kill_ob(inven[k],1);

    tmp = new("/d/common/obj/weapon/spear_lg");
    tmp->set_property("enchantment",3);
    if(ob->Thaco(1,TP,tmp) < (random(20)+4))
    {
        tell_object(TP,"You are hit with a spear!");
        tell_room(TO,TPQCN+" is hit with a spear.",TP);
        ob->do_hits(TP, tmp, "torso");
    }
    if(ob->Thaco(1,TP,tmp) < (random(20)+4))
    {
        tell_object(TP,"You are hit with a spear!");
        tell_room(TO,TPQCN+" is hit with a spear.",TP);
        ob->do_hits(TP, tmp, "torso");
    }
    j = random(5)+4;
    for(i=0;i<j;i++)
    {
        k = random(sizeof(inven));
        if(ob->Thaco(1,inven[k],tmp) < (random(20)+4))
        {
            tell_object(inven[k],"You are hit with a spear!");
            tell_room(TO,inven[k]->query_cap_name()+" is hit with a spear.",inven[k]);
            ob->do_hits(inven[k], tmp, "torso");
        }
    }
    TP->add_attacker(ob);
    TP->continue_attack();
// adding check for objectp(TP) to try to stop bugging *Styx*  11/15/02
    if(objectp(TP))  TP->remove_attacker(ob);
    tmp->remove();    // added by Styx 11/03/02 to clean up objects w/no environment
    tell_room(TO,"Natives appear from the bushes and attack.");

    toggle_trap(verb);
    return 1;
}

void init(){
    if(flag)
    {
        reset();
        flag =0;
    }
    ::init();
}

string query_long(string str)
{
    string hold,one,two;

    hold = ::query_long(str);

    if(!what) return hold;

    sscanf(what,"%s&%s",one,two);
    if(!one || !trapped(two)) return hold;

    switch (one)
    {
        case "native":
        hold += "The bushes seem to shake every now and then.";
        return hold;
        break;
        case "tasloi":
        hold += "The trees are strangely quiet";
        return hold;
        break;
        case "ankheg":
        hold += "The ground is looser than the rest of this path.";
        return hold;
        break;
    }

    return hold;
}
