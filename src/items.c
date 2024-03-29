#include "items.h"

void vpulseSetV(vpulse *vp, struct buffer_wave *buffer, double global_time,
                double time_step, int wave_shift) {
  if ((vp->state == 1) && (vp->local_time > vp->period / 2)) {
    vp->state = 0;
    vp->local_time = 0;
  } else if ((vp->state == 0) && (vp->local_time > vp->period / 2)) {
    vp->state = 1;
    vp->local_time = 0;
  }
  buffer[wave_shift].x = global_time;
  buffer[wave_shift].y = vp->state;
  vp->local_time = vp->local_time + time_step;
}

void capSetV(cap *c, struct buffer_wave *buffer, double global_time,
             double time_step, int wave_shift) {
  double res_current =
      ((c->input_voltage - c->current_voltage) / c->resistance);
  c->charge = c->charge + (res_current / time_step);
  c->current_voltage = c->charge / c->capacitance;

  buffer[wave_shift].x = global_time;
  buffer[wave_shift].y = c->current_voltage;
  c->local_time = c->local_time + time_step;
}

void capInit(cap *c) {
  c->local_time = 0;
  c->current_voltage = 0;
  c->input_voltage = 0;
  c->resistance = 5;
  c->capacitance = 5;
  c->charge = 0;
}

void vpulseInit(vpulse *vp) {
  vp->local_time = 0;
  vp->state = 1;
  vp->v_hi = 1;
  vp->v_low = 0;
  vp->period = 50;
}
