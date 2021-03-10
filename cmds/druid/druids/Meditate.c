// Pator@ShadowGate
// The meditate command for druids (or priests)
// This command addes spell_points to players
// They are paralyzed during the process
// Jul 16 1996

#include <std.h>

// Used general variables
int m_beat, cancel, *spells_per_level;

// Related to the mistletoe
string save_file;
object mistletoe;

// Used functions
int cmd_meditate();
int begin_meditation(object tp);
int cancel_meditate();
int finish_meditate(object obj);
int cancel_it(int complete);

int cmd_meditate(){
        mixed *values;
        int number_can_cast; 	
	set_author("pator");
	mistletoe = present("mistletoe",TP);
	if (!mistletoe)
	  { write("%^RED%^You don't have a mistletoe !!\nPlease try again when you have one !!");
	  return 0; }
        cancel = 0;
	values = mistletoe->query_spell_values();
	spells_per_level = values[2];
        if(!(int)TP->query_property("spell_points"))
	  {  number_can_cast = 0; }
        else 
	  {   number_can_cast = (int)TP->query_property("spell_points"); }
        if(number_can_cast > 5){
                write("You cannot meditate again, until you have used all of your casting uses.");
                return 1;
        }
	TP->set_paralyzed(300,
	       "You are meditating, and must keep your mind clear!");
	write("You begin to meditate. \nPress <ENTER> to cancel meditation.");
        m_beat = 0;
        call_out("begin_meditation",5,TP);
        input_to("cancel_meditate",1);
        return 1;
}

int cancel_meditate()
{       cancel = 1;
        return 1; }


int finish_meditate(object obj){
        int total,inc;
        total = 1;
        for(inc = 0; inc < 7; inc++){
                total += spells_per_level[inc] * (inc + 1);
        }
        if(obj->query_level() < 5)
                total = total*4;
        else 
                total = total*2;
        message("meditate","You have "+total+" resources to cast spells. Use them wisely!",obj);
        obj->set_property("spell_points",total);
        obj->remove_paralyzed();
	return 1;
}


int begin_meditation(object tp){
        string name,posess,dname;
        name = (string)tp->query_true_name();
        posess = (string)tp->query_possessive();
        dname = capitalize(tp->query_diety());
        m_beat++;
	switch(m_beat){
          case 1: if(cancel) { cancel_it(1); m_beat = 0;return 0;}
                message("meditate","You slowly free your mind of all things, and focus on your diety, "+dname,tp);
                message("meditate",name+"'s eyes roll back into "+posess+"
head.",environment(tp),tp);
                break;
        case 2: if(cancel) { cancel_it(2);m_beat = 0; return 0;}
                message("meditate","You can no longer hear what goes on around you.",tp);
                message("meditate",name+"'s body sways back and forth.",environment(tp),tp);
                break;
        case 3: if(cancel) { cancel_it(3); m_beat = 0;return 0;}
                message("meditate","You lose all your senses, as your mind floats out, seeking "+dname+".",tp);
                message("meditate",name+"'s body continues to sway back and
forth.",environment(tp),tp);
                break;
        case 4: if(cancel) { cancel_it(4); m_beat = 0;return 0;}
                message("meditate","Slowly, your minds eyes spots something. You try to focus on it.",tp);
                message("meditate",name+"'s body continues to sway back and
forth.",environment(tp),tp);
                break;
        case 5: if(cancel) { cancel_it(5); m_beat = 0;return 0;}
                message("meditate","Suddenly, your mind is filled with the vision of "+dname+".",tp);
                message("meditate",name+"'s body continues to sway back and
forth.",environment(tp),tp);
                break;
        case 6: if(cancel) { cancel_it(6); m_beat = 0;return 0;}
                message("meditate",""+dname+" looks down at you. Fear and awe fill your inner being.",tp);
                message("meditate",name+"'s body continues to sway back and
forth.",environment(tp),tp);
                break;
        case 7: if(cancel) { cancel_it(7); m_beat = 0;return 0;}
                message("meditate","Slowly "+dname+" looks you over. You feel your soul being touched by the diety.",tp);
                message("meditate",name+"'s body continues to sway back and
forth.",environment(tp),tp);
                break;
        case 8: if(cancel) { cancel_it(8); m_beat = 0;return 0;}
                message("meditate","Suddenly "+dname+" is gone.",tp);
                message("meditate",name+"'s body continues to sway back and
forth.",environment(tp),tp);
                break;
        case 9: if(cancel) { cancel_it(9); m_beat = 0;return 0;}
                message("meditate","You feel your mind returning to your body.",tp);
                message("meditate",name+" seems to come out of "+posess+"
trance.",environment(tp),tp);
                break;

        default: break; }
         if(m_beat < 10) { call_out("begin_meditation",5,tp);}
         else { call_out("finish_meditate",5,tp); }
        return 1;
}
int cancel_it(int complete){
        message("meditate","You feel your mind returning to your body.",TP);
        message("meditate","You quit meditating to do other things.",TP);
        cancel = 0;
        TP->remove_paralyzed();
}
