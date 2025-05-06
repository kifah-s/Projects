import {
  AfterViewInit,
  Component,
  DestroyRef,
  effect,
  inject,
  OnDestroy,
  OnInit,
  signal,
} from '@angular/core';

@Component({
  selector: 'app-server-status',
  standalone: true,
  imports: [],
  templateUrl: './server-status.component.html',
  styleUrl: './server-status.component.css',
})
export class ServerStatusComponent implements OnInit {
  currentStatus = signal<'online' | 'offline' | 'unknown'>('offline');

  // private interval?: ReturnType<typeof setInterval>;
  private destroyRef = inject(DestroyRef);

  constructor() {
    //   setInterval(() => {
    //     const rnd = Math.random(); // 0 - 1

    //     if (rnd < 0.5) {
    //       this.currentStatus = 'online';
    //     } else if (rnd < 0.9) {
    //       this.currentStatus = 'offline';
    //     } else {
    //       this.currentStatus = 'unknown';
    //     }
    //   }, 5000);

    // console.log(this.currentStatus());
    effect(() => {
      console.log(this.currentStatus());
    });
  }

  ngOnInit() {
    console.log('OnINIT');

    const interval = setInterval(() => {
      const rnd = Math.random(); // 0 - 1

      if (rnd < 0.5) {
        this.currentStatus.set('online');
      } else if (rnd < 0.9) {
        this.currentStatus.set('offline');
      } else {
        this.currentStatus.set('unknown');
      }
    }, 5000);

    this.destroyRef.onDestroy(() => {
      clearInterval(interval);
    });
  }

  // ngAfterViewInit() {
  //   console.log('AFTER VIEW INIT');
  // }

  // ngOnDestroy() {
  //   clearTimeout(this.interval);
  // }
}
