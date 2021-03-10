//      /std/bag_logic.c
//      from the Nightmare mudlib
//      an inheritable container object
//      based on the broken bag_logic.c created by Brian November 1991
//      written by Descartes of Borg 04 October 1992
//      lockable functions added 21 October 1992 by Descartes
//  cleaned up some fail messages to be more meaningful, also changed to consistently use #defines for ETO, TP, etc. to make it more readable, last change was 10/02 *Styx 8/19/03
//   added item_allowed() function to enable having special restrictions at the item level *Styx*  11/30/04
// edited to allow items to be put into containers on the ground, and to give the right message when putting something onto a table. Lujke 2016 

#include <std.h>
#include <move.h>
#include <daemons.h>
#include <security.h>

inherit CONTAINER;
string open_long_desc;
string closed_long_desc;
string *open_riddles = ({});
string *open_riddle_answers = ({});
string *riddle_solvers = ({});

mapping lock_data;
int lock_dif, solve_once = 1;
void toggle_lock();
int item_allowed(object item);  // use this function at the object level if needed, don't call this one *Styx*  12/04/04

void init() 
{
        ::init(); //added by Saide in an attempt to fix the 
    //bug where writing cannot be read on certain objects (contains specifically
    //in dealing with this file) - June 08
        add_action("get_from","get");
        add_action("put_into","put");
        add_action("open_container","open");
        add_action("close_container","close");
        add_action("unlock_container", "unlock");
        add_action("lock_container", "lock");
        add_action("PickLock","pick");
}

varargs receive_objects(object ob)

{
        //Added in order to fix lockable chests so that 
        //you cant put items into them while they are locked 
        //this assumes that if a chest is locked it is therefore 
        //also closed - Saide - 8/24/07
        //write(identify(TO));
        if(!objectp(TO)) return ::receive_objects(ob);
        if(!TO->query_lock_data()) 
        {
                return ::receive_objects(ob);
        }
        if((string)TO->query_lock_data("status") == "locked")
        {
                if(!TO->query_closed()) 
                {
                        TO->set_closed(1);
                }
        }       
        return ::receive_objects(ob);
}

void set_open_riddle(mixed str)
{
        if(!str) 
        {
                str = ({});
        }
        if(!sizeof(str))
        {
                str = ({str});
        }
        open_riddles = str;
}

void set_open_riddle_answers(mixed str)
{
        if(!str) 
        {
                str = ({});
                set_open_riddle(str);
        }
        if(!sizeof(str)) 
        {
                str = ({str});
        }
        open_riddle_answers = str;
}

int set_solve_only_once(int x)
{
        solve_once = x;
        return solve_once;
}

int isMagic(){
    int p;
    int n, i;
    object * inven;
    p = ::isMagic();
    inven = all_inventory(TO);
    for (i = 0;i<sizeof(inven);i++) {
        n = inven[i]->isMagic();
        p = p<n?n:p;
    }
    return p;
}

status query_lock_data(string str) {
    if(!str) {
        if(!lock_data) {  return 0; } 
        else {  return 1; }
    }
    switch(str) {
        case "status":
            return lock_data["status"];
        case "key":
            return lock_data["key"];
    }
}

int query_value(){
    int val;
    int n, i;
    object * inven;
    
    val = ::query_value();
    inven = all_inventory(TO);
    for (i = 0;i<sizeof(inven);i++) {
        val += inven[i]->query_value();
    }
    return val;
}

int item_allowed(object item) {
    return 1;   // to have a default in for when it's not restricted
}

int is_table(){ return -1;} //added by lujke, to allow for tables

int put_into(string str) 
{
    int res, i, silly;

    object ths,tht,*inv,shapeshift_restricted_commands;
    string this, that, prep, desc;

    if(TP->query_bound() || TP->query_unconscious())
    {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }

/* It makes sense that they could fumble around even in total darkness and
manage.  Would they maybe drop it, fumble it, etc. yeah but that's too much
coding for too little return to deal with.  This is a real and unrealistic
problem for people who log out in daylight and log in to darkness too dark
to get their lantern out, etc. *Styx*  12/23/03, last change 8/19/03
   if(total_light(TP)+(int)TP->query_sight_bonus()<-1) {
      notify_fail("It is too dark.\n");
      return 0;
   }
*/



    if(stringp(str) && sscanf(str,"%s in %s",this,that) == 2) 
    {
       
if(objectp(shapeshift_restricted_commands=to_object("/std/races/shapeshifted_races/restricted_commands")))
        {
            if(!avatarp(TP))
            {
               
if(!shapeshift_restricted_commands->allow_shifted_command(TP,"put",this+""+that))
                {
                    tell_object(TP,"You can't put "+this+" in "+that+"while shapeshifted.");
                    destruct(shapeshift_restricted_commands);
                    return 1;
                }
            }
        }

        if(present(this,TP)) 
        {
            if(present(that,TP) || present(that,ETP)) 
            {
                ths = present(this,TP);
                tht = present(that, TP);
                
                if(ths == tht) 
                { /* Plura 930208 */
                    notify_fail("Get real!\n");
                    return 0;
                }
            
//reversed the order of the next two lines, to make it possible to put
// stuff in a container on the ground. Lujke
                if(!tht) tht = present(that, ETP);        
                   if(tht != TO) return 0;               
                                               
                if(ths->drop()) 
                {
                    notify_fail("You cannot do that!\n");
                    return 0;
                }
            
                if(tht->receive_objects()) 
                {
                        if(!tht->item_allowed(ths)) 
                    {
                                notify_fail("You fail to put "+ths->query_short()+" in"+tht->query_short()+".\n");
                                return 0;
                    }

      
                    if(ths->is_baggy() &&  sizeof(all_inventory(ths))) 
                    {
                        notify_fail("You realize "+ths->query_short()+" is too full to fit into "+tht->query_short()+".\n");
                        return 0;
                    }
               
                    desc = tht->query_short(); //getting this before changing contents because some containers now 
                                             // change short description to reflect contents. Lujke 2016
                    res = (int)ths->move(tht);
                    //next line added, and write lines altered to give correct message 
                    // when putting something on a table. Lujke
                    if (is_table()) {prep = " on ";} else {prep = " in ";}
                    if(res == MOVE_OK) 
                    {
                        write("You put "+ths->query_short()+ prep 
                                                +desc+".\n");
                        tell_room(ETP,TPQCN+" puts "+ths->query_short()+ prep 
                                                 +desc+".",TP);
                        return 1;
                    }
                    
                    if(res == MOVE_NO_ROOM) { notify_fail("For some reason it does not fit...\n"); }
               
                    if(res == MOVE_NOT_ALLOWED) { notify_fail("You are not allowed to do that...\n"); }
               
                    return 0;
                }
            
                notify_fail("It is closed.\n");
                return 0;         
            }
         
            notify_fail(capitalize(that)+" is not here.\n");
            return 0;
        }
      
        notify_fail("You are not carrying "+this+".\n");
        return 0;
    }
    return 0;
}

int get_from(string str) 
{
    int silly, res, i;
    object ob, tmp, *inv,shapeshift_restricted_commands;
    string what, where;
   
    if(!stringp(str)) return 0;
    if(TP->query_ghost()) return 0;
    if(TP->query_bound() || TP->query_unconscious()) 
    { 
        TP->send_paralyzed_message("info",TP);
        return 1;
    }

/* See above in put_into() for why this is commented out *Styx*
   if(total_light(TP)+(int)TP->query_sight_bonus()<-1) {
      notify_fail("It is too dark.\n");
      return 0;
   }
*/

    if(sscanf(str, "%s from %s", what, where) != 2) return 0;
   
if(objectp(shapeshift_restricted_commands=to_object("/std/races/shapeshifted_races/restricted_commands")))
    {
        if(!avatarp(TP))
        {
           
if(!shapeshift_restricted_commands->allow_shifted_command(TP,"get",what+""+where))
            {
                tell_object(TP,"You can't get "+what+" from "+where+" while shapeshifted.");
                destruct(shapeshift_restricted_commands);
                return 1;
            }
        }
    }

    if(id(where)) tmp = TO;
    else tmp = parse_objects(ETO, where);
    if(tmp != TO) return 0;
   
    if(TO->receive_objects()) 
    {
        if(what != "all") 

        {
         ob = present(what, TO);
         if(!ob) ob = parse_objects(TO, what);
         if(!ob) {
            write("There is no "+what+" in "+TO->query_short()+".");
            return 1;
         }
         res = (int)ob->move(TP);
         if(res == MOVE_OK) {
             if(objectp(ob))
             {
                write("You get "+ob->query_short()+" from "
                                            +TO->query_short()+".");
                tell_room(ETP,TPQCN+" gets "+ob->query_short()+" from "
                                         +TO->query_short()+".", TP);
                return 1;
             }
         }
         if(res == MOVE_NOT_ALLOWED) write("You can't do that!");
         if(res == MOVE_NO_ROOM) write("You can't carry that!");
         return 1;
      }
      inv = all_inventory(TO);
      if(!sizeof(inv)) {
         write("There is nothing in "+TO->query_short()+".");
         return 1;
      }
      for(i=0; i<sizeof(inv); i++) {
         res = (int)inv[i]->move(TP);
         if(res == MOVE_OK) {
            write("You get "+inv[i]->query_short()+" from "
                                              +TO->query_short()+".");
            tell_room(ETP,TPQCN+" gets "+inv[i]->query_short()+" from "
                                            +TO->query_short()+".", TP);
         }
         if(res == MOVE_NO_ROOM) write(inv[i]->query_short()
                                                     +": Too heavy.\n");
      }
      return 1;
   }
   write(query_short()+" is closed.");
   return 1;
}

void set_closed_long(string str) {   closed_long_desc = str; }

void set_open_long(string str) {     open_long_desc = str;   }

string query_open_long_desc() {      return open_long_desc;  }

string query_closed_long_desc() {    return closed_long_desc;}

string query_cont_long(){   return container::query_long("");}

string query_long(string str) {
   object *inv;
   int i;
   string desc;
   // added by lujke, to deal with a problem where chests appeared to be
   // closed even when open. March 2008
   if (query_possible_to_close()){  
     if (query_closed()){
       desc = query_closed_long_desc();
     } else {
       desc = query_open_long_desc();
     }
   } 
   if (!stringp(desc)){
     desc = container::query_long(str);
   }
 // end of additions by lujke
// desc = container::query_long(str); This line replaced by additions above
   if((int)TO->receive_objects() || (int)TO->clear()) {
      inv = all_inventory(TO);
      if(sizeof(inv) > 0 ) {
         if(stringp(desc))
            desc += "  It contains:\n";
         else desc = "  It contains:\n";
         for(i=0;i<sizeof(inv);i++)
         {
            if(inv[i]->is_disease()) continue;
            desc += "  "+ (string)inv[i]->query_short()+"\n";
         }
      }
   }
   return desc;
}

void riddle_header()
{
        write("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"+
        "=-=-=-=-");
}

mixed do_riddle_open(object ch)
{
        int which_riddle;
        string current_riddle, riddle_answer;
        if(!objectp(ch)) 
        {
                write("That is not here!");
                return 1;
        }
        if(!sizeof(open_riddles) || !sizeof(open_riddle_answers))
        {
                write("Something is wrong with this chest... the riddle "+
                "is messed up.  Please contact a wiz.");
                return 1;
        }
        which_riddle = random(sizeof(open_riddles));
        current_riddle = open_riddles[which_riddle];
        riddle_answer = open_riddle_answers[which_riddle];
        riddle_header();
        write(current_riddle);
        input_to("answer_open_riddle", 0, current_riddle, riddle_answer, ch);
        riddle_header();
        write("Please type your answer or type ~q to quit.");
        riddle_header();
}

void answer_open_riddle(string input, string riddle, string answer, object
ch)
{
        if(input == "~q")
        {
                riddle_header();
                write("Exiting riddle.");
                riddle_header();
                return;
        }
        if(!input || input != answer && input != 0)
        {
                riddle_header();
                write("Wrong!  Please try again.\n");
                write(riddle);
                riddle_header();
                input_to("answer_open_riddle", 0, riddle, answer, ch);
                riddle_header();
                write("Please type your answer or type ~q to quit.");
                riddle_header();
                return;
        }
        if(input == answer)
        {
                riddle_header();
                write("That is correct!");
                riddle_header();
                riddle_solvers += ({environment(ch)->query_name()});
                if((string)ch->query_open_long_desc())
                {
                        
                    ch->set_long((string)ch->query_open_long_desc());
              ch->toggle_closed();
                        write("You open "+ch->query_short()+".");
                        tell_room(ETP,TPQCN+" opens "+       
              ch->query_short()+ ".",TP);
                        return;
                }
                return;
        }
}       

int open_container(string str) {
    object ch;
    if(!stringp(str)) {
        tell_object(TP,"Open what?");
        return 1;
    }
    ch = present(str,TP);
    if(!ch) ch = present(str,ETP);
    if(!ch) { return 0; }
    if(!ch->is_bag()) return 0;

    if(TP->query_bound() || TP->query_unconscious()){
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    if(ch->query_lock_data()) {
         if((string)ch->query_lock_data("status") == "locked") {
            write("It is locked.\n");
            return 1;
         }
    }
           if(sizeof(open_riddles) && (!solve_once ||
           member_array(environment(ch)->query_name(), riddle_solvers) == -1)) {
                   do_riddle_open(ch);
                   return 1;
           }
    if(ch->receive_objects())
        write("It is already open.");
      else {
                if(ch->is_trapped("open")) 
                {
                        if(ch->execute_trap("open", TP)) return 1;
                }
                if(ch->trapped("open"))                 
                {
                if(ch->do_spec_trap("open"))
                return 1;
                }
           if(sizeof(open_riddles) && (!solve_once ||
           member_array(environment(ch)->query_name(), riddle_solvers) == -1)) 
           {
                   do_riddle_open(ch);
                   return 1;
           }

         if((string)ch->query_open_long_desc())
            ch->set_long((string)ch->query_open_long_desc());
            ch->toggle_closed();
           POISON_D->is_object_poisoned(ch, TP, "open", 1);
         write("You open "+ch->query_short()+".");
         tell_room(ETP,TPQCN+" opens "+       
                   ch->query_short()+ ".",TP);
      }
   return 1;
}

int close_container(string str) {
    object ch;
    
    if(!stringp(str)) {
        tell_object(TP,"Close what?");
        return 1;
    }
    
    ch = present(str,TP);

    if(!ch) ch = present(str,ETP);
    if(!ch) { return 0; }
    if(!ch->is_bag()) return 0;
        
    if(TP->query_bound() || TP->query_unconscious()){
        TP->send_paralyzed_message("info",TP);
        return 1;
    }

    if(!ch->receive_objects())
         write("It is already closed.");
    else
        if(!ch->toggle_closed())
            write("It cannot be closed.");
        else {
                if(ch->is_trapped("close")) 
                {
                        if(ch->execute_trap("close", TP)) return 1;
                }
         if(ch->trapped("close")) {
            if(ch->do_spec_trap("close")) return 1;
         }
         if(ch->query_closed_long_desc())
            ch->set_long((string)ch->query_closed_long_desc());
         write("You close "+ch->query_short()+".");
           POISON_D->is_object_poisoned(ch, TP, "close", 1);
         tell_room(ETP,TPQCN+" closes "+ 
                   ch->query_short()+".",TP);
      }
    return 1;
}

int lock_container(string str) {
    object ch;
   if(!str) {
      notify_fail("Lock what?\n");
      return 0;
   }
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   ch = present(str,TP);
   
   if(!ch) ch = present(str,ETP);
   if(!ch) { 
      notify_fail("No '"+str+"' here or bad syntax.\n");
      return 0;
   }
   if(!ch->is_bag()) return 0;

   if(!ch->query_lock_data()) {
      write("That "+str+" does not seem to have a lock.\n");
      return 1;
   }
   if(ch->receive_objects()) {
      write("It must be closed before you can lock it.\n");
      return 1;
   }
   if((string)ch->query_lock_data("status") == "locked") {
      write("It is already locked!\n");
      return 1;
   }
   if((string)ch->query_lock_data("key") 
   && present((string)ch->query_lock_data("key"), TP)) {
      write("You lock the "+str+".\n");
      tell_room(ETP,TPQCN+" locks the "+str+".\n",TP);
      ch->toggle_lock();
      return 1;
   } else if(!ch->query_lock_data("key")) {
      write("You lock the "+str+".\n");
      tell_room(ETP,TPQCN+" locks the "+str+".\n",TP);
      ch->toggle_lock();
      return 1;
   } else {
      write("Lock the "+str+" with what?\n");
      return 1;
   }
}

int unlock_container(string str) {
    object ch;
   if(!str) {
      notify_fail("Unlock what?\n");
      return 0;
   }
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   ch = present(str,TP);
   if(!ch) ch = present(str,ETP);
   if(!ch) { 
      notify_fail("No '"+str+"' found.  If you are trying to unlock a door,\n "
        "try <unlock [door id] with [key id]>.  If there are multiple "
        "locks,\n try <unlock [lock id] on [door id] with [key id]>.\n");
      return 0;
   }
   if(!ch->is_bag()) return 0;
   if(!ch->query_lock_data()) {
      notify_fail("That "+str+" does not seem to have a lock.\n");
      return 0;
   }
   if((string)ch->query_lock_data("status") != "locked") {
      notify_fail("The "+str+" is not locked.\n");
      return 0;
   }
   if(!ch->query_lock_data("key")) {
      write("You unlock the "+str+".\n");
      tell_room(ETP,TPQCN+" unlocks the "+str+".\n",TP);
      ch->toggle_lock();
      return 1;
   }
   if(!present((string)ch->query_lock_data("key"), TP)) {
      notify_fail("Unlock the "+str+" with what?\n");
      return 0;
   }
        if(ch->is_trapped("unlock")) 
        {
                if(ch->execute_trap("unlock", TP)) return 1;
        }
        if(ch->trapped("unlock")) 
        {
        if(ch->do_spec_trap("unlock")) return 1;
        }
        
   write("You unlock the "+str+".\n");
   tell_room(ETP,TPQCN+" unlocks the "+str+".\n",TP);
   ch->toggle_lock();
   return 1;
}

void toggle_lock() {
   if(!lock_data) return;
   if(lock_data["status"] == "locked") lock_data["status"] = "unlocked";
   else lock_data["status"] = "locked";
}

int query_locked() {
   if(!lock_data) return 0;
   if(lock_data["status"] == "locked") return 1;
   else return 0;
}

void set_lock(string stat) {
   if(stat != "locked" && stat != "unlocked") {
      if(!lock_data) lock_data = ([ "status": "locked" ]);
      else lock_data["status"] = "locked";
      return;
   }
   if(!lock_data) lock_data = ([ "status": stat ]);
   else lock_data["status"] = stat;
}
void set_key(string str) {
   if(!lock_data) lock_data = ([]);
   lock_data["key"] = str;
}
int is_bag() {return 1;}
void lock_difficulty( int mod) {
   lock_dif = mod;     
}
int query_mod(string str) {return lock_dif;}

int PickLock(string str) {
   object ob;
   object ob2;
   object ch;
   int level;
   int mydiff,modifier,score,percent;
   if(!str) {
      notify_fail("Pick what?\n");
      return 0;
   }
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   ch = present(str,TP);
   if(!ch) ch = present(str,ETP);
   if(!ch) { return 0; }

   if(!ch->query_lock_data()) {
      notify_fail("It does not have a lock.\n");
      return 0;
   }
   if((string)ch->query_lock_data("status") != "locked") {
      notify_fail("It is not locked.\n");
      return 0;
   }
   if(!ch->query_lock_data("key")) {
      write("You unlock the "+str+".\n");
      tell_room(ETP,TPQCN+" unlocks the "+str+".\n",TP);
      ch->toggle_lock();
      return 1;
   }

   if( !( ob=present("thief toolx", TP) ) ) {
      if(present("broken tool", TP)) {
         write("You can't use those broken tools.\n");
      }
      notify_fail("You do not have the tools!\n");
      return 0;
   }
/*   if(!TP->is_class("thief")) {
      notify_fail("You can't do that.\n");
      return 0;
   } */
   modifier = ch->query_mod();
   score = TP->query_skill("dungeoneering") + modifier + roll_dice(1,20);
        if(ch->is_trapped("pick")) 
        {
                if(ch->execute_trap("pick", TP)) return 1;
        }
   if(ch->trapped("pick")) {
      if(ch->do_spec_trap("pick")) return 1;
   }

   mydiff = 20;
   if(score >= mydiff) {
      write("You unlock the "+str+".\n");
      tell_room(ETP,TPQCN+" unlocks the "+str+".\n",TP);
      ch->toggle_lock();
      return 1;
   } else {
      write("The lock doesn't seem to budge.\n");
      write("You worry about your tools.\n");
      tell_room(environment(TP),"You see "+TPQCN+" struggle to pick
"+str+".",TP);
      if((percent - score) > 30) {
         level = TP->query_level();
         percent = random(99);
         if(percent > (70 + level*2)) {
            ob2 = present("tools", TP);
            ob2->break_picks();
            return 1;
         }
      }
      return 1;
   }
}

int save_me(string file) {
   object *inv;
   string path, who,fn, fname, *stuff;
   int x,y,i, j, num;


   /*
   if(sscanf(file,"/inv/%s/%s", who, path) != 2)
      return ::save_me(file);
   if(sscanf(path,"ob%d",num) != 1)
      return ::save_me(file);
     */

   stuff = explode(file,"/");
   fn = stuff[sizeof(stuff)-1];
   path = "/";
   for (i=0;i<sizeof(stuff)-1;i++) {
       path +=stuff[i];
       path += "/";
   }
   seteuid(UID_ROOT);
   inv = all_inventory(TO);
   y = sizeof(inv);
   if(y) {

      for(x = 0; x < y; x++) {
         //     tell_object(ob,"Saving Object #"+x+"\n");
         fname = path+"save"+x+fn;
         j=inv[x]->save_me(fname);
      }
   }
   ::save_me(file);
   seteuid(getuid());
}


void db(string str)
{
    if(objectp(find_player("ares")))
    {
        tell_object(find_player("ares"),str);
    }
}


int restore_me(string file) 
{
        string *files, fname, fn,who,item, path, *stuff;
        int fsize;
        int x, i, j, holder,num, cstate, lstate;
        mixed tmp;

        holder = ::restore_me(file);


        seteuid(UID_ROOT);
  
        sscanf(file,"/inv/%s/%s", who, path);
   
        if(stringp(path))
        sscanf(path,"ob%d",num);

        fsize = sizeof(files = get_dir("/inv/"+who+"/"+num+"save*"));
        //I fixed this since before it would never even work at all
        // should look like save0ob1 - not 0save1 - Saide

        //fsize = sizeof(files = get_dir("/inv/"+who+"/save*ob"+num+".o"));

        for(x = 0; x < (fsize) ; x++) 
        {
        //    write("Loading Object #"+x);
        fname = "/inv/"+who+"/"+files[x];
            tmp = "/daemon/yuck_d"->restore_files(fname);
        if(stringp(tmp)) 
                {
                write(tmp);
                    rm(fname);
        } 
                else 
                {
                cstate = (int)TO->query_closed();
                lstate = (int)TO->query_locked();
                if(cstate == 1) 
                        {
                TO->set_closed(0);
                }
                if(lstate == 1) 
                        {
                        TO->set_locked(0);
                }
                if(tmp->move(TO) != MOVE_OK) 
                        {       
                                tmp->move(find_object_or_load(TP->getenv("start")));                           
                        write("You dropped "+tmp->query_short()+ " from a container!");
                }
                TO->set_locked(lstate);
                TO->set_closed(cstate);
                //tmp->restore_me(fn+".o");
                rm(fname);
        }
        }
        //what exactly is this?  Saide
        stuff = explode(file,"/");
        fn = stuff[sizeof(stuff)-1];
        path = "/";
        for (i=0;i<sizeof(stuff)-1;i++) 
        {
        path +=stuff[i];
        path += "/";
        }

    i=0;

        fsize = sizeof(files = get_dir(path +"save*"+fn+".*"));
        for(x = 0; x < (fsize) ; x++) 
        {
        //    write("Loading Object #"+x);
                //tell_object(TP, "Using 2nd loop...");
        fname = path + files[x];

        tmp = "/daemon/yuck_d"->restore_files(fname);

        if(!read_file(fname))
        {
            db("fname: "+fname+" is empty");
        }

        if(stringp(tmp) || !tmp) 
                {
            if(tmp) { write(tmp); }                     
            rm(fname);
        } 
                else 
                {
                cstate = (int)TO->query_closed();
                lstate = (int)TO->query_locked();
                if(cstate == 1) 
                        {
                        TO->set_closed(0);
                }
                if(lstate == 1) 
                        {
                        TO->set_locked(0);
                }
            if(objectp(TP))
            {
                if((string)TP->query_name() == "testsubject")
                {
                                    tell_object(TP, "trying to move "+
                                        "tmp ("+identify(tmp)+ " short = "+tmp->query_short()+
                                        " ) to TO ( "+identify(TO)+" )");
                }
            }

                if(tmp->move(TO) != MOVE_OK) 
                        {
                        tmp->move(find_object_or_load(TP->getenv("start")));
                                write("You dropped "+tmp->query_short()+ " from a container!");

                        //write("You dropped something from a container!");
                }
                TO->set_locked(lstate);
                TO->set_closed(cstate);
                //tmp->restore_me(fn+".o");
                rm(fname);
        }
        }
        seteuid(getuid());
}

void remove() {

   object *inven;
   int i, j;
   inven = all_inventory(TO);

   if(!TO->is_corpse()) {
      j = sizeof(inven);
      if(j)
         for(i=0;i<j;i++)
            inven[i]->remove();
   }
   return ::remove();
}
int is_baggy() {return 1;}
