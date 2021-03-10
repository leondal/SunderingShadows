//    /bin/adm/_callouts.c
//    From the Nightmare mudlib
//    Coded by Valodin on Feb 4, 1993

#include <str_fmt.h>
#include <std.h>
inherit DAEMON;

int cmd_callout(string str) {
  mixed *crap;
  mixed *element;
  object ob;
  string func, filename, trash, spaces;
  int i, j, delay, num;
  mixed args;
  string printing_crap;
  string *junk,*display=({});


  crap = call_out_info();
// adding this for optional arguments  *Styx*  11/11/02
  if(str && str != "corpses" && str != "no corpses")
     return notify_fail("Please use <callout corpses> to see just corpses or "
	"<callout no corpses> to see without them and keep from overflowing the buffer.\n");
  if(!sizeof(crap))  {
    write("There are no call_outs right now.\n");
    return 1;
  }

  write("%^BOLD%^%^GREEN%^Object                    Function             Delay  Arguments\n" +
        "%^BLUE%^---------------------------------------------------------------");

  for(i = 0; i < sizeof(crap); i++)  
  {
    element = crap[i];
    if(sizeof(element) != 4)  {
      //write("Size problem " + sizeof(element) + " " + element + " \n");
        display += ({ "Size problem " + sizeof(element) + " " + element + " \n"  });
      continue;
    }
    ob = (object)element[0];
    func = (string)element[1];
    delay = (int)element[2];
    args  = element[3];
    filename = file_name(ob);
    junk = explode(filename,"/");
    num = sizeof(junk);
    filename = junk[num-1];
// adding this for optional arguments  *Styx*  11/11/02
    if(str != "all") {
    if(str == "corpses" && (strsrch(filename, "corpse") == -1))
	continue;
    if(str == "no corpses" && (strsrch(filename, "corpse") != -1) )  
	continue;
    }
    printing_crap = sprintf("%%^YELLOW%%^%-25s %%^MAGENTA%%^%-20s %%^CYAN%%^%5d",filename,func,delay);

    if(sizeof(args)){
      for(j = 0; j < sizeof(args); j++)
        if(sizeof(args[j]))
          printing_crap += "  <ARRAY:" + sizeof(args[j]);
        else 
          if(objectp(args[j]))
            if(args[j]->is_player())
              printing_crap += "  " + args[j]->query_cap_name();
            else
            {
              filename = file_name(args[j]);
    	      junk = explode(filename,"/");
	      num = sizeof(junk);
    	      filename = junk[num-1];
              printing_crap += "  " + filename;
            }
    }
    else{
      if(objectp(args)){
        if(args->is_player())
          printing_crap += "  " + args->query_cap_name();
        else
        {
          	filename = file_name(args);
    	      	junk = explode(filename,"/");
	      	num = sizeof(junk);
    	      	filename = junk[num-1];
          	printing_crap += "  " + filename;
	}
      }
    }
    if(!args)
	printing_crap += "  %^BOLD%^%^BLACK%^------";
    //write(printing_crap);
    display += ({ printing_crap });
  }
    //write("%^BLUE%^---------------------------------------------------------------");
  display += ({ "%^BLUE%^---------------------------------------------------------------" });

  TP->more(display);

  return 1;
}

int help() {
  write("Command: callout [ corpses | no corpses ]\n\n" +
        "This command lists all the call_outs on the mud.\n" +
	"Styx - added so corpses are skipped if specified or to get only corpses.\n"
	   "Was overflowing buffer with all after corpses got longer decay delay.\n"
        "See man: call_out_info\n"+
        "See also: cache, mstatus, minfo, netstat, fdinfo, opcprof, dumpallobj\n"+
        "" );
  return 1;
}
