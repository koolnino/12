#include <furi.h>
#include <gui/gui.h>
#include "loc_lac.xbm"

void lacviewer_draw(Canvas* canvas, void* ctx) {
    UNUSED(ctx);
    canvas_clear(canvas);
    canvas_draw_xbm(canvas, 0, 0, loc_lac_width, loc_lac_height, loc_lac_bits);
}

int32_t app_main(void* p) {
    UNUSED(p);
    Gui* gui = furi_record_open("gui");
    ViewPort* viewport = view_port_alloc();
    view_port_draw_callback_set(viewport, lacviewer_draw, NULL);
    gui_add_view_port(gui, viewport, GuiLayerFullscreen);
    furi_delay_ms(3000); // Affiche l'image pendant 3 secondes
    gui_remove_view_port(gui, viewport);
    view_port_free(viewport);
    furi_record_close("gui");
    return 0;
}