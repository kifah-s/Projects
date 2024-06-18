const model = document.querySelector(".model");
const loginBtn = document.querySelector(".login-btn");
const closeBtn = document.querySelector(".close");

loginBtn.addEventListener("click", openModel);
closeBtn.addEventListener("click", closeModel);
window.addEventListener("click", outsideClick);

function openModel() {
  model.style.display = "block";
}

function closeModel() {
  model.style.display = "none";
}

function outsideClick(e) {
  if (e.target == model) {
    closeModel();
  }
}
