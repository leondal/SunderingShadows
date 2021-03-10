#ifndef __OLD_ROOM_H
#define __OLD_ROOM_H

#ifdef __SENSES_C
void set_search_string(string item, string desc) { 
    set_search(item, desc);
}

void set_search_func(string item, string func) { 
    set_search(item, (: this_object(), func :));
}

void remove_search_string(string item) { remove_search(item); }

void remove_search_func(string item) { remove_search(item); }

void set_smell_string(string item, string desc) { set_smell(item, desc); }

void set_smell_func(string item, string func) {
    set_smell(item, (: this_object(), func :));
}

void remove_smell_string(string item) { remove_smell(item); }

void remove_smell_func(string item) { remove_smell(item); }

void set_listen_string(string item, string desc) {
    set_listen(item, desc);
}

void set_listen_func(string item, string func) {
    set_listen(item, (: this_object(), func :));
}

void remove_listen_string(string item) { remove_listen(item); }

void remove_listen_func(string item) { remove_listen(item); }
#endif // __SENSES_C

#endif /* __OLD_ROOM_H */
