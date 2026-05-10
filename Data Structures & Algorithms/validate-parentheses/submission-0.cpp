class Solution {
public:
    bool isValid(string s) {
        const int rows =
            static_cast<int>(img.size());

        const int cols =
            static_cast<int>(img[0].size());

        std::vector<std::vector<int>> smoothedImage(
            rows,
            std::vector<int>(cols)
        );

        for (int row = 0;
             row < rows;
             ++row) {

            for (int col = 0;
                 col < cols;
                 ++col) {

                int pixelSum = 0;
                int validCells = 0;

                for (int rowOffset = -1;
                     rowOffset <= 1;
                     ++rowOffset) {

                    for (int colOffset = -1;
                         colOffset <= 1;
                         ++colOffset) {

                        const int nextRow =
                            row + rowOffset;

                        const int nextCol =
                            col + colOffset;

                        if (nextRow >= 0 &&
                            nextRow < rows &&
                            nextCol >= 0 &&
                            nextCol < cols) {

                            pixelSum +=
                                img[nextRow][nextCol];

                            ++validCells;
                        }
                    }
                }

                smoothedImage[row][col] =
                    pixelSum / validCells;
            }
        }

        return smoothedImage;
    }
};
