

void hideItem(object item, object hider, int hiddenProf){
    //assume we can hide it
     hiddenProf += 5;
     hiddenProf -= (int)item->query_weight();
     hiddenProf = hiddenProf<0?0:hiddenProf;
    item->set_hidden(hiddenProf);
    item->reset_hidden_seen();
    item->add_hidden_seen(hider);
}

int checkFound(object what, int prof){
    int hidden;
   hidden = what->query_real_hidden(); // changed by lujke 01 Mar 2008.
                                      // previously just used query_hidden()
                                     // which returns a binary result
    return (random(prof)+1 >= hidden);

}

object * searchContainer(object cont, object who){
    int prof, i, max_search_level, search_level;
    int hidden;
    object *inven, *found;

    //prof = who->query_nwp("concealment");
    prof = (int)who->query_skill("thievery") / 2;
    max_search_level = prof + (int)who ->query_highest_level()/2;
    search_level = max_search_level/2 + max_search_level/4 +1;
    found = ({});
    inven = all_inventory(cont);
    for (i=0;i<sizeof(inven);i++) {
          if(inven[i] == who) continue;
        if (inven[i]->query_hidden()) {
            if (checkFound(inven[i], search_level)){
                inven[i]->add_hidden_seen(who);
                found += ({inven[i]});
            }
        }
    }

    return found;

}
