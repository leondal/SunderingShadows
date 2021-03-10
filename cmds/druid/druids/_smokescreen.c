// A smokescreen for druids
// This is part of the druidic symbol
// Pator@ShadowGate
// Jan 25 1996

int cmd_smokescreen();
int cmd_smokescreen()
{ object where,tp;
  string *exits,go_to,txt,tptn,poss,subj;
  int i,go_invis;  
                 // Ok a few helpvariables
  tp = this_player();
  tptn = (string)tp->query_true_name();
  tptn = capitalize(tptn);
  poss = tp->query_possessive();
  subj = tp->query_objective();
                // Where am I and where am I going ?
  where = environment(tp);
  exits = where->query_exits();
  i = random(sizeof(exits));
  go_to = where->query_exit(exits[i]);
  if (!go_to) go_to = "/d/shadowgate/adv_main";
               // Tell them that you are GONE !
  txt = " waved with "+poss+
        " mistletoe and suddenly :\na blueish white smoke makes "+subj;
  tell_room(where,
      tptn+txt+" disappear from your sight !!\n", ({tp}));
  tp->move(go_to); 
  tp->force_me("look");
  tell_player(tp,
	    "You waved your mistletoe !  You went to this room !!\n\n");
  return 1;
}
