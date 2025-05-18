void basicPatterns(const string& username){
    const string& level = "BASIC";
    vector<string> basicPatternsOption = {
        "[1] Solid Square",
        "[2] Hollow Square",
        "[3] Left-Padded Right Angled Triangle",
        "[4] Right Angled Triangle",
        "[5] Inverted Right Triangle",
        "[6] Return",
    };

    int choice = patternDifficultyDashboard(basicPatternsOption);

    switch(choice){
        case 0: solidSquare(level, username); break;
        case 1: hollowSquare(level, username); break;
        case 2: rightAngleLeftAlignedTri(level, username); break;
        case 3: rightAngleRightAlignedTri(level, username); break;
        case 4: invertAngleTri(level, username); break;
        case 5: break;
    }
}void Guest::dashboard() {
    clearScreen();
    int choice = 0;
    

        vector<string> options = {
            "[1] Visualize Algorithm",
            "[2] Visualize Data Structure",
            "[3] Patterns Generator",
            "[4] Logout"
        };
        
        choice = showMenuVisualize("Visualizer Menu:", options);


        clearScreen();
        switch (choice) {
            case 0: visualizeAlgorithm(); break;
            case 1: visualizeDataStructure(); break;
            case 2: patternGenerator(); break;
            case 3: std::cout << "Logging out...\n"; break;
        }

    
    
}void Guest::patternGenerator(){
        vector<string> patternDifficultyOptions = {
        "[1] Basic",
        "[2] Intermediate",
        "[3] Complex",
        "[4] Return"
    };

    int difficultyOption = patternDifficultyDashboard(patternDifficultyOptions);

    switch(difficultyOption){
        case 0: basicPatterns(username); break;
        case 1: intermediatePatterns(username);break;
        case 2: complexPatterns();break;
        case 3: dashboard(); break;
    }
}