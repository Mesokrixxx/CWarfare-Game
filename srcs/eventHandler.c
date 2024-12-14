# include "eventHandler.h"

// Init an event
Event *eventConstructor(int keycode, void (*action)(void *content, Game *game), void *linkedContent) {
    Event *e = calloc(1, sizeof(struct s_event));
    
    e->keycode = keycode;
    e->action = action;
    e->linkedContent = linkedContent;
    return (e);
}

// Free an event
void freeEvent(Event *e) {
    free(e);
}

// Init an event handler
EventHandler *initEventHandler() {
    EventHandler *eh = calloc(1, sizeof(struct s_eventhandler));

    eh->events = initDynamicList(sizeof(struct s_event));
    return (eh);
}

// Add an event to an event handler
void addEventToEventHandler(EventHandler *eh, Event *e) {
    appendToDList(eh->events, e);
}

// When a key is pressed, this function is called and the matching event is executed
void callEvents(EventHandler *eh, int keycode, Game *game) {
    for (int i = 0; i < eh->events->size; i++) {
        Event *e = (Event *)eh->events->content[i];
        if (e->keycode == keycode)
            e->action(e->linkedContent, game);
    }
}
