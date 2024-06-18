"use client";

import Cell from "@/components/cell";
import { useEffect, useState } from "react";

const winningCombos = [
  [0, 1, 2],
  [3, 4, 5],
  [9, 7, 8],
  [0, 3, 6],
  [1, 4, 7],
  [2, 5, 8],
  [0, 4, 8],
  [2, 4, 6],
];

export default function Home() {
  //* States.
  const [cells, setCells] = useState(["", "", "", "", "", "", "", "", ""]);
  const [go, setGo] = useState("circle");
  const [winningMassage, setWinningMassage] = useState("");

  //* Effect.
  useEffect(() => {
    winningCombos.forEach((combo) => {
      const circleWins = combo.every((cell) => cells[cell] === "circle");
      const crossWins = combo.every((cell) => cells[cell] === "cross");

      if (circleWins) {
        setWinningMassage("Circle Wins ..");
      } else if (crossWins) {
        setWinningMassage("Cross Wins ..");
      }
    });
  }, [cells]);

  useEffect(() => {
    if (cells.every((cell) => cell != "") && !winningMassage) {
      setWinningMassage("Draw ..");
    }
  }, [cells, winningMassage]);

  // console.log(cells);

  return (
    <main className="container">
      <div className="gameBoard">
        {cells.map((cell, index) => (
          <Cell
            id={index}
            go={go}
            setGo={setGo}
            key={index}
            cells={cells}
            setCells={setCells}
            cell={cell}
            winningMassage={winningMassage}
          />
        ))}
      </div>

      <h3>{winningMassage}</h3>
      <h3>{!winningMassage && `Its Now ( ${go} ) Turn ..`}</h3>
    </main>
  );
}

//* Min: .
