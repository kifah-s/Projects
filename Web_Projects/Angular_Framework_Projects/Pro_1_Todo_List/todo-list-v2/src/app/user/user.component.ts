import { Component, Input, Output, EventEmitter } from '@angular/core';
import { type User } from './user.model';

@Component({
  selector: 'app-user',
  templateUrl: './user.component.html',
  styleUrl: './user.component.css',
})
export class UserComponent {
  // Input.
  @Input({ required: true }) user!: User;
  @Input({ required: true }) selected!: boolean;

  // Output.
  @Output() select = new EventEmitter<string>();

  // Getter.
  get imagePath() {
    return 'assets/users/' + this.user.avatar;
  }

  onSelectUser() {
    this.select.emit(this.user.id);
  }
}
