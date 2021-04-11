import App from "./app";

const app = new App();

app.server.listen(3001, () => {
  console.log("Ordis Systems Up");
});
