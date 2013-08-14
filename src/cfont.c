#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"

#define MY_UUID { 0x8C, 0x72, 0x26, 0x5A, 0x9D, 0x65, 0x4E, 0x2A, 0xB9, 0xD9, 0x7A, 0x52, 0x28, 0x1F, 0xB4, 0xFF }
PBL_APP_INFO(MY_UUID, "cfont", "kumkee", 1, 0 /* App version */, RESOURCE_ID_IMAGE_MENU_ICON, APP_INFO_WATCH_FACE);

Window window;

TextLayer text_chinese_layer1;
TextLayer text_chinese_layer2;
TextLayer text_chinese_layer3;
TextLayer text_chinese_layer4;
//TextLayer text_time_layer;

Layer line_layer;


void line_layer_update_callback(Layer *me, GContext* ctx) {

  graphics_context_set_stroke_color(ctx, GColorWhite);

  graphics_draw_line(ctx, GPoint(0, 84), GPoint(143, 84));
  graphics_draw_line(ctx, GPoint(0, 85), GPoint(143, 85));

}


void handle_init(AppContextRef ctx) {

  static char sample_text1[] = "一二三四五廿正初";
  static char sample_text2[] = "六七八九十月閏";

  window_init(&window, "CFont");
  window_stack_push(&window, true /* Animated */);
  window_set_background_color(&window, GColorBlack);

  resource_init_current_app(&APP_RESOURCES);


  text_layer_init(&text_chinese_layer1, window.layer.frame);
  text_layer_set_text_color(&text_chinese_layer1, GColorWhite);
  text_layer_set_background_color(&text_chinese_layer1, GColorClear);
  layer_set_frame(&text_chinese_layer1.layer, GRect(0, 5, 168, 40));
  text_layer_set_font(&text_chinese_layer1, fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_WQYZH_CCAL_18)));
  text_layer_set_text(&text_chinese_layer1, sample_text1);
  layer_add_child(&window.layer, &text_chinese_layer1.layer);

  text_layer_init(&text_chinese_layer2, window.layer.frame);
  text_layer_set_text_color(&text_chinese_layer2, GColorWhite);
  text_layer_set_background_color(&text_chinese_layer2, GColorClear);
  layer_set_frame(&text_chinese_layer2.layer, GRect(0, 45, 168, 40));
  text_layer_set_font(&text_chinese_layer2, fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_WQYZH_CCAL_18)));
  text_layer_set_text(&text_chinese_layer2, sample_text2);
  layer_add_child(&window.layer, &text_chinese_layer2.layer);


  text_layer_init(&text_chinese_layer3, window.layer.frame);
  text_layer_set_text_color(&text_chinese_layer3, GColorWhite);
  text_layer_set_background_color(&text_chinese_layer3, GColorClear);
  layer_set_frame(&text_chinese_layer3.layer, GRect(0, 91, 168, 40));
  text_layer_set_font(&text_chinese_layer3, fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_IPAG_CCAL_18)));
  text_layer_set_text(&text_chinese_layer3, sample_text1);
  layer_add_child(&window.layer, &text_chinese_layer3.layer);

  text_layer_init(&text_chinese_layer4, window.layer.frame);
  text_layer_set_text_color(&text_chinese_layer4, GColorWhite);
  text_layer_set_background_color(&text_chinese_layer4, GColorClear);
  layer_set_frame(&text_chinese_layer4.layer, GRect(0, 131, 168, 40));
  text_layer_set_font(&text_chinese_layer4, fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_IPAG_CCAL_18)));
  text_layer_set_text(&text_chinese_layer4, sample_text2);
  layer_add_child(&window.layer, &text_chinese_layer4.layer);

  /*
  text_layer_init(&text_time_layer, window.layer.frame);
  text_layer_set_text_color(&text_time_layer, GColorWhite);
  text_layer_set_background_color(&text_time_layer, GColorClear);
  layer_set_frame(&text_time_layer.layer, GRect(7, 92, 144-7, 168-92));
  text_layer_set_font(&text_time_layer, fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_ROBOTO_BOLD_SUBSET_49)));
  layer_add_child(&window.layer, &text_time_layer.layer);
  */


  layer_init(&line_layer, window.layer.frame);
  line_layer.update_proc = &line_layer_update_callback; layer_add_child(&window.layer, &line_layer);


  // TODO: Update display here to avoid blank display on launch?
}


/*
void handle_minute_tick(AppContextRef ctx, PebbleTickEvent *t) {

  // Need to be static because they're used by the system later.
  static char time_text[] = "00:00";
  //static char date_text[] = "Xxxxxxxxx 00";

  char *time_format;


  // TODO: Only update the date when it's changed.
  //string_format_time(date_text, sizeof(date_text), "%B %e", t->tick_time);
  //text_layer_set_text(&text_chinese_layer, date_text);


  if (clock_is_24h_style()) {
    time_format = "%R";
  } else {
    time_format = "%I:%M";
  }

  string_format_time(time_text, sizeof(time_text), time_format, t->tick_time);

  // Kludge to handle lack of non-padded hour format string
  // for twelve hour clock.
  if (!clock_is_24h_style() && (time_text[0] == '0')) {
    memmove(time_text, &time_text[1], sizeof(time_text) - 1);
  }

  text_layer_set_text(&text_time_layer, time_text);

}
*/


void pbl_main(void *params) {
  PebbleAppHandlers handlers = {
    .init_handler = &handle_init,

    /*.tick_info = {
      .tick_handler = &handle_minute_tick,
      .tick_units = MINUTE_UNIT
    }*/

  };
  app_event_loop(params, &handlers);
}
