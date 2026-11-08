// theme.js
// Switches between light and dark themes and remembers the choice.

const root = document.documentElement;
const button = document.querySelector(".theme-toggle");
const label = button.querySelector(".theme-toggle__label");

// Work out which theme is showing right now
function currentTheme() {
    if (root.dataset.theme) return root.dataset.theme;
    const prefersDark = window.matchMedia("(prefers-color-scheme: dark)").matches;
    return prefersDark ? "dark" : "light";
}

// The button names the theme you'd switch TO
function updateButton() {
    const theme = currentTheme();
    label.textContent = theme === "dark" ? "Light" : "Dark";
    button.setAttribute("aria-pressed", theme === "dark");
}

button.addEventListener("click", function () {
    const next = currentTheme() === "dark" ? "light" : "dark";
    root.dataset.theme = next;
    try {
        localStorage.setItem("theme", next);
    } catch (e) {
        // Storage can be blocked (private windows); the toggle still works
    }
    updateButton();
});

updateButton();
