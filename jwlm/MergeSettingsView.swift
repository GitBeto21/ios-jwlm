//
//  MergeSettingsView.swift
//  jwlm
//
//  Created by Andreas Skorczyk on 11.10.20.
//

import SwiftUI

struct MergeSettingsView: View {
    @ObservedObject var jwlmController: JWLMController
    
    // @State private var expanded: Bool = true
    @State private var bookmarkSolverIcon = "minus.circle"
    @State private var markingSolverIcon = "minus.circle"
    @State private var noteSolverIcon = "minus.circle"

    var body: some View {
        VStack {
            HStack {
                Text("Conflict Autoresolution")
                    .underline()
                Spacer()
            }
            .padding([.top, .leading, .trailing])
            HStack {
                VStack {
                    Menu {
                        Button(action: {
                            jwlmController.settings.bookmarkResolver = conflictSolver.disabled
                            bookmarkSolverIcon = confSolverToIcon(solver: jwlmController.settings.bookmarkResolver)
                        }) {
                            Text("Manual")
                            Image(systemName: "minus.circle")
                        }
                        Button(action: {
                            jwlmController.settings.bookmarkResolver = conflictSolver.chooseLeft
                            bookmarkSolverIcon = confSolverToIcon(solver: jwlmController.settings.bookmarkResolver)
                        }) {
                            Text("Left")
                            Image(systemName: "arrow.left")
                        }
                        Button(action: {
                            jwlmController.settings.bookmarkResolver = conflictSolver.chooseRight
                            bookmarkSolverIcon = confSolverToIcon(solver: jwlmController.settings.bookmarkResolver)
                        }) {
                            Text("Right")
                            Image(systemName: "arrow.right")
                        }
                    } label: {
                        Image(systemName: "bookmark")
                    }
                    Image(systemName: bookmarkSolverIcon)
                        .font(.footnote)
                        .foregroundColor(.gray)
                        .padding(.top, 0.3)
                }
                Spacer()
                VStack {
                    Menu {
                        Button(action: {
                            jwlmController.settings.markingResolver = conflictSolver.disabled
                            markingSolverIcon = confSolverToIcon(solver: jwlmController.settings.markingResolver)
                        }) {
                            Text("Manual")
                            Image(systemName: "minus.circle")
                        }
                        Button(action: {
                            jwlmController.settings.markingResolver = conflictSolver.chooseLeft
                            markingSolverIcon = confSolverToIcon(solver: jwlmController.settings.markingResolver)
                        }) {
                            Text("Left")
                            Image(systemName: "arrow.left")
                        }
                        Button(action: {
                            jwlmController.settings.markingResolver = conflictSolver.chooseRight
                            markingSolverIcon = confSolverToIcon(solver: jwlmController.settings.markingResolver)
                        }) {
                            Text("Right")
                            Image(systemName: "arrow.right")
                        }
                    } label: {
                        Image(systemName: "pencil.tip")
                    }
                    Image(systemName: markingSolverIcon)
                        .font(.footnote)
                        .foregroundColor(.gray)
                        .padding(.top, 0.3)
                }
                Spacer()
                VStack {
                    Menu {
                        Button(action: {
                            jwlmController.settings.noteResolver = conflictSolver.disabled
                            noteSolverIcon = confSolverToIcon(solver: jwlmController.settings.noteResolver)
                        }) {
                            Text("Manual")
                            Image(systemName: "minus.circle")
                        }
                        Button(action: {
                            jwlmController.settings.noteResolver = conflictSolver.chooseNewest
                            noteSolverIcon = confSolverToIcon(solver: jwlmController.settings.noteResolver)
                        }) {
                            Text("Newest")
                            Image(systemName: "sparkles")
                        }
                        Button(action: {
                            jwlmController.settings.noteResolver = conflictSolver.chooseLeft
                            noteSolverIcon = confSolverToIcon(solver: jwlmController.settings.noteResolver)
                        }) {
                            Text("Left")
                            Image(systemName: "arrow.left")
                        }
                        Button(action: {
                            jwlmController.settings.noteResolver = conflictSolver.chooseRight
                            noteSolverIcon = confSolverToIcon(solver: jwlmController.settings.noteResolver)
                        }) {
                            Text("Right")
                            Image(systemName: "arrow.right")
                        }
                    } label: {
                        Image(systemName: "note.text")
                    }
                    Image(systemName: noteSolverIcon)
                        .font(.footnote)
                        .foregroundColor(.gray)
                        .padding(.top, 0.3)
                }
            }
            .font(.title2)
            .padding()
        }
    }
}

struct MergeSettingsView_Previews: PreviewProvider {
    static var previews: some View {
        let jwlmController = JWLMController()
        MergeSettingsView(jwlmController: jwlmController)
    }
}

func confSolverToIcon(solver: conflictSolver) -> String {
    switch solver {
    case .disabled:
        return "minus.circle"
    case .chooseLeft:
        return "arrow.left"
    case .chooseRight:
        return "arrow.right"
    case .chooseNewest:
        return "sparkles"
    }
}
