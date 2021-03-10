#include <std.h>

inherit ROOM;

mapping visitors;

void init(){
    ::init();
    if(!wizardp(this_player()))
      add_action("filter_act", "", 1);
    call_out("begin_death", 4, TP);
}

void create(){
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no teleport", 1);
    set_short("The void between life and death");
    set_long( (:this_object(), "d_long":) );
    skip_obvious();
    visitors = ([]);
}

string d_long() { return ""; }

int filter_act(string str){
    if(query_verb() == "says" || query_verb() == "tell" || query_verb() == "shout"){
      write("You let out a haunting wail!\n");
    } else {
      write("The dead are incapable of such acts.\n");
    }
    return 1;
}

void begin_death(object tp){
    if(wizardp(tp) && !tp->query_property("long death")){
      tell_object(tp, "%^BOLD%^%^CYAN%^Well, you ended up here in death land.  It's a good thing`you're immortal because it just saved you from a lengthy spiel.  Well, get back in there and get cracking!  I'm sure you can think of somthing productive to do.  P.S.  If you want to see the whole death seaquence, add the property 'long death' to yourself.%^RESET%^\n");
      if(tp->query_ghost())
        tp->move_player("/d/shadow/room/city/church");
      return;
    }
    tell_object(tp, "%^GREEN%^You feel yourself in the endless void.  You think you are moving, yet you may not be.  Time means nothing, space means nothing.\n");
    call_out("do_death1", 3, tp);
}

void do_death1(object tp){
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;

    tell_object(tp, "The darkness starts to receede.\n");
    tell_object(tp, "%^BOLD%^A bright light flashes before your eyes!");
    tell_object(tp, "%^YELLOW%^You find yourself standing up on a large platform above a crowd of people around a gigantic wooden table.  Food covers the table, but most of it has been spilled from its containers.\n");
    call_out("do_death2", 4, tp);
}

void do_death2(object tp){
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;

    tell_object(tp, "%^MAGENTA%^%^BOLD%^The entire room is in chaos.  All around people are doing battle, whether it be with food, their bare hands, weapons, or even the furniture, but amazingly nobody ever seems to be getting hurt.\n");
    call_out("do_death3", 2, tp);
}

void do_death3(object tp){
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;

    tell_object(tp, "%^CYAN%^As you watch you see great warriors of old mixed in the crowd.  Here there are many greats that have fallen in combat.\n");
    tell_object(tp, "%^GREEN%^Suddenly you hear one of them yell, \"A NEW WARRIOR HAS FALLEN!!\" and all eyes suddenly turn up to you.\n");
    call_out("do_death4", 2, tp);
}

void do_death4(object tp){
    tell_object(tp, "%^YELLOW%^Strong unseen hands push you from behind, and you fall down into the crowd of men and women.  They pick you up and throw you around until you find yourself being put in an oversized ornately carved wooden chair at the head of the table.\n");
    call_out("do_death5", 5, tp);
}

void do_death5(object tp){
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;

    tell_object(tp, %^BOLD%^%^RED%^A rather large man wearing a great horned helmet and large hides pushes his way through the other warriors to the head of the table  He looks at you, and then clasps you on the shoulder with a smile.\n");
    call_out("do_death6", 3, tp);
}

void do_death6(object tp){
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;

   tell_object(tp, "%^MAGENTA%^Olaf the Viking%^RESET%^:  Fellow warriors, another great one has joined us!!");
    tell_object(tp, "A cheer rises from the men and women in the room!\n");
    call_out("do_death7", 3, tp);
}

void do_death7(object tp){
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;

    tell_object(tp, "%^MAGENTA%^Olaf the Viking%^RESET%^:  Another great one has fallen in battle, and has come to join us for eternal feast and battle in Valhalla!!");
    tell_object(tp, "Another great cheer rises from the room!\n");
    call_out("do_death8", 3, tp);
}

void do_death8(object tp){
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;

    tell_object(tp, "Olaf turns and looks at you.");
    tell_object(tp, "%^MAGENTA%^Olaf the Viking%^RESET%^:  So how does it feel to have joined the greatest warriors of all time in this place known as Valhalla, to feast with us, to fight with us, to live for the eternal battle!!\n");
    call_out("do_death9", 4, tp);
}

void do_death9(object tp){
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;

    tell_object(tp, "The look in Olaf's eyes turns to sadness as he looks you over.");
    tell_object(tp, "%^MAGENTA%^Olaf the Viking%^RESET%^:  Yet some do not believe you belong here.  Some feel you died too easily to be allowed in this hall of heros.  I said you fought valiantly as a true warrior would, I doubt many here would do as well, but they think you could have done better.\n");
    call_out("do_death10", 4, tp);
}

void do_death10(object tp){
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;

