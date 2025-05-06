import {
  AfterViewInit,
  Component,
  ElementRef,
  EventEmitter,
  OnInit,
  output,
  Output,
  viewChild,
  ViewChild,
} from '@angular/core';

import { FormsModule } from '@angular/forms';

import { ButtonComponent } from '../../../shared/button/button.component';
import { ControlComponent } from '../../../shared/control/control.component';

@Component({
  selector: 'app-new-ticket',
  standalone: true,
  imports: [ButtonComponent, ControlComponent, FormsModule],
  templateUrl: './new-ticket.component.html',
  styleUrl: './new-ticket.component.css',
})
export class NewTicketComponent implements OnInit, AfterViewInit {
  @ViewChild('form') private form?: ElementRef<HTMLFormElement>;
  // private form = viewChild.required<ElementRef<HTMLFormElement>>('form');
  // @Output() add = new EventEmitter<{ title: string; text: string }>();
  enteredTitle = '';
  enteredText = '';
  add = output<{ title: string; text: string }>();

  ngOnInit() {
    console.log('ON INIT');
    console.log(this.form?.nativeElement);
  }

  ngAfterViewInit() {
    console.log('AFTER VIEW INIT');
    console.log(this.form?.nativeElement);
  }

  onSubmit() {
    // console.log('SUBMITTED !!');
    // console.log(titleElement); // Output as a "Input".
    // console.dir(titleElement); // Output as a "Object".
    // console.log(titleElement.value); // Output as a "Value".

    // const enteredTitle = titleElement.value;
    // console.log('ENTERED TITLE:' + enteredTitle); // Output as a "Value".

    // console.log(title);
    // console.log(ticketText);

    // this.add.emit({ title: title, text: ticketText });

    // this.form()?.nativeElement.reset();
    // this.form?.nativeElement.reset();

    this.add.emit({ title: this.enteredTitle, text: this.enteredText });
    this.enteredTitle = '';
    this.enteredText = '';
  }
}
