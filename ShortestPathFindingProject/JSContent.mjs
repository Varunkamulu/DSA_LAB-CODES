import Grid from "./app/Grid/Grid.class.mjs"
import gridConfig from './app/config/grid.config.mjs';
const grid = new Grid(gridConfig);
grid.build();
grid.draw();
console.log(grid.settings);