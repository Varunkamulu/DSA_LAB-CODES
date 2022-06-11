
class Grid
{
    constructor()
    {

    }
    build()
    {
        this.#buildGridLayout();
        this.#buildGridCells();
        this.#buildGridSvg();
    }
    get gridElement()
    {
        return document.querySelector(this.settings.gridSelector)
    }
    #buildGridLayout()
    {
        const {settings,gridElement}=this;
        const {cellSize,borderSize,borderColor}=settings;
        const {innerWidth,innerHeight}=window;

        const fullCellSize = cellSize + borderSize*2;
        this.numCols = Math.floor( innerHeight/fullCellSize);
        this.numRows = Math.floor(innerHeight/fullCellSize);
    }
    #buildGridCells()
    {

    }
    #buildGridSvg()
    {}
    draw()
    {}
}
export default Grid