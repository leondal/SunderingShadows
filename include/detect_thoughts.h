{
    object* listeners;
    object listener;
    listeners = all_inventory(ETP);
    listeners = filter_array(listeners, (: $1->is_living() :));
    listeners = filter_array(listeners, (:query_property("detecting_thoughts"):));
    if (sizeof(listeners)) {
        foreach(listener in listeners)
        {
            tell_object(listener, "%^BOLD%^%^RED%^TP->QCN communicates with " + ob->QCN + ".%^RESET%^");
            if (TP->query_stats("intelligence") - listener->query_stats("intelligence") > 10) {
                tell_object(TP, "%^BOLD%^%^RED%^You sense your telepathy is being detected.%^RESET%^");
                listener->set_paralyzed(2 * roll_dice(1, 4) - 1, "Interception of your detection attempts leave you stunned.");
                listener->remove_property("detection_thoughts");
            }
        }
    }
}
